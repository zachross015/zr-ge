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


struct life : public zr::renderable {

    arma::Mat<unsigned int> board;
    unsigned int m, n;

    int i = 0;

    life(arma::Mat<unsigned int> configuration) : board(configuration), m(configuration.n_rows), n(configuration.n_cols) { };

    unsigned int count_neighbors(unsigned int i, unsigned int j) {
        unsigned int val = 0;
        for (int k = i - 1; k <= i + 1; k++) {
            for (int l = j - 1; l <= j + 1; l++) {
                if(!(k == i && l == j) && (k >= 0 && k < m) && (l >= 0 && l < n)) {
                    val += board(k, l); 
                }
            }
        }
        return val;
    }


    unsigned int next_val(unsigned int i, unsigned int j) {
        unsigned int num_neighbors = count_neighbors(i, j);
        if(board(i, j)) {
            return !(num_neighbors < 2 || num_neighbors > 3);
        } else {
            return num_neighbors == 3;
        }
    }


    arma::Mat<unsigned int> next_board() {
        arma::Mat<unsigned int> nb = arma::Mat<unsigned int>(m, n);
        for (int i = 0; i < m; ++i) {
           for (int j = 0; j < n; ++j) {
                nb(i, j) = next_val(i, j); 
           } 
        }
        return nb;
    }
    
    void render(zr::renderer* r) {

        r->draw_color({255, 255, 255, 255});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board(i, j)) {
                    r->draw_points({i, j});
                }
            }
             
        }

        i = (i + 1) % 1;
        if(i == 0) {
            board = next_board();
        }

    }

};

int main(int argc, char* argv[]) {

    // Initalize window and renderer
    zr::window window = zr::window("Hello", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, { zr::opengl });
    zr::renderer renderer = zr::renderer(window, {zr::accelerated});

    // Initialize persistent variables
    int gameover = 0;
    SDL_Event event;

    // Determine the size of the game of life texture and items
    float aspect_ratio = ((float) SCREEN_WIDTH)  / SCREEN_HEIGHT;
    int life_height = 100;
    int life_width = (aspect_ratio * life_height);

    // Construct the board configuration randomly
    float size = 100;
    arma::mat configuration_float = arma::randu<arma::mat>(life_width, life_height);
    arma::Mat<unsigned int> configuration = arma::Mat<unsigned int>(life_width, life_height);
    for (int i = 0; i < life_width; ++i) {
        for (int j = 0; j < life_height; ++j) {
            configuration(i, j) = configuration_float(i, j) > 0.5; 
        }
    }
    life l(configuration);

    // Construct the texture to draw the game to
    zr::target_texture t(renderer, {life_width, life_height});

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

        // Target the texture so we can zoom in on the situation
        renderer.target(&t);

        // Clear the texture and render the game of life
        renderer.clear({ 0, 0, 0, 255 });
        renderer.render(&l);
        
        // Target the window and copy the texture back to the screen
        renderer.target_window();
        renderer.copy(&t, {}, {});

        // Present everything 
        renderer.present();
    }

    IMG_Quit();
    SDL_Quit();
    return 0;
}

