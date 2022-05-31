#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <cmath>

#include <exceptions.h>
#include <underlying_types.h>

#include <sdl_wrapper.h>

#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH    1920
#define SCREEN_HEIGHT   1080


struct procedural_noise_2d : public zr::renderable {

    arma::mat chunk_anchors;
    arma::mat pixels;
    zr::size_i<unsigned int> cs, d;
    bool constructed;

    virtual double interpolate(arma::mat, arma::mat) = 0;
    
    procedural_noise_2d(zr::size_i<unsigned int> cs, zr::size_i<unsigned int> d) : cs(cs), d(d)  {
        auto chunk_dim = d.size() / cs.size();

        auto m = (d.width() / cs.width()) + 1;
        auto n = (d.height() / cs.height()) + 1;
        chunk_anchors.randn(m, n);
        pixels.zeros(m * cs.width(), n * cs.height());

        constructed = false;


    }

    void render(zr::renderer* r) {

        if(!constructed) {
            auto m = (d.width() / cs.width()) + 1;
            auto n = (d.height() / cs.height()) + 1;
            for (int i = 0; i < m - 1; ++i) {
                for (int j = 0; j < n - 1; ++j) {
                    for (int k = 0; k < cs.width(); ++k) {
                        for (int l = 0; l < cs.height(); ++l) {
                            pixels((i * cs.width()) + k, (j * cs.height()) + l) = 
                                interpolate({k , l}, chunk_anchors.submat(i, j, i + 1, j + 1));
                        }
                    } 
                }
            }
            constructed = true;
        }

        for (int i = 0; i < pixels.n_rows; ++i) {
            for (int j = 0; j < pixels.n_cols; ++j) {
                r->draw_color({255, 255, 255, 255 * pixels(i, j)});
                r->draw_points({i, j});
            }
        }
    
    }

};

struct linear_noise : public procedural_noise_2d {

    linear_noise(zr::size_i<unsigned int> cs, zr::size_i<unsigned int> d) : procedural_noise_2d(cs, d) {}

    virtual double interpolate(arma::mat indices, arma::mat anchors)  {
        auto k = indices(0);
        auto l = indices(1);
        auto p1 = anchors(0, 0);
        auto p2 = anchors(0, 1);
        auto p3 = anchors(1, 0);
        auto p4 = anchors(1, 1);

        float x_lerp_c = 1 - ((float) k) / cs.width();
        float y_lerp_c = 1 - ((float) l) / cs.height();

        auto x_upper = (p1 * x_lerp_c) + (p3 * (1 - x_lerp_c));
        auto x_lower = (p2 * x_lerp_c) + (p4 * (1 - x_lerp_c));
        return (x_upper * y_lerp_c) + (x_lower * (1 - y_lerp_c));
    }

};

struct cosine_noise : public procedural_noise_2d {

    cosine_noise(zr::size_i<unsigned int> cs, zr::size_i<unsigned int> d) : procedural_noise_2d(cs, d) {}

    virtual double interpolate(arma::mat indices, arma::mat anchors)  {
        auto k = indices(0);
        auto l = indices(1);
        auto p1 = anchors(0, 0);
        auto p2 = anchors(0, 1);
        auto p3 = anchors(1, 0);
        auto p4 = anchors(1, 1);

        float x_lerp_c = 1 - ((float) k) / cs.width();
        float y_lerp_c = 1 - ((float) l) / cs.height();

        auto x_upper = (p1 * x_lerp_c) + (p3 * (1 - x_lerp_c));
        auto x_lower = (p2 * x_lerp_c) + (p4 * (1 - x_lerp_c));
        return (x_upper * y_lerp_c) + (x_lower * (1 - y_lerp_c));
    }

};


int main(int argc, char* argv[]) {

    // Initalize window and renderer
    zr::window window = zr::window("Hello", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, { zr::opengl });
    zr::renderer renderer = zr::renderer(window, {zr::accelerated});


    int width = 800;
    int height = width / (SCREEN_WIDTH / SCREEN_HEIGHT);
    zr::target_texture t(renderer, {width, height});

    // Initialize persistent variables
    int gameover = 0;
    SDL_Event event;

    linear_noise pn({8, 8}, {width, height});

    while(!gameover) {
        if(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    gameover = 1;
                    break;
            }
        }



        // Clear the window
        renderer.target_window();
        renderer.clear({ 0, 0, 0, 255 });

        renderer.target(&t);
        renderer.clear({ 0, 0, 0, 255 });
        renderer.render(&pn);
        renderer.target_window();
        renderer.copy(&t);

        // Present everything 
        renderer.present();
    }

    IMG_Quit();
    SDL_Quit();
    return 0;
}

