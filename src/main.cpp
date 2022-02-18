#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <cmath>

#include <exceptions.h>
#include <mutable_size.h>

#include<sdl_wrapper.h>

#include <SDL.h>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

int main(int argc, char* argv[]) {

    zr::window window = zr::window("Hello", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, { zr::opengl, zr::resizable });
    window.title("Hello world");
    window.width(1600);
    window.height(900);

    zr::renderer renderer = zr::renderer(window, {zr::accelerated});
    zr::texture texture = zr::texture(renderer, 
            zr::pixel_format_specifier::argb_8888, 
            zr::texture_access::target_access, 
            {SCREEN_WIDTH, SCREEN_HEIGHT});

    int gameover = 0;
    SDL_Event event;
    auto start = std::chrono::system_clock::now();

    while(!gameover) {
        if(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    gameover = 1;
                    break;
            }
        }

        // Calculate time differential
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<float> elapsed_time = now - start;
        float dt = elapsed_time.count();
        
        zr::mutable_size screen_size = window.size();
        float x = screen_size.width() / 4.0;
        float y = screen_size.height() / 4.0;
        float w = screen_size.width() / 2.0;
        float h = screen_size.height() / 2.0;

        w *= cos(dt);
        h *= cos(dt);

        // Clear the window
        renderer.target_window();
        renderer.draw_color({ 0, 0, 0, 255 });
        renderer.clear();

        // Draw the lines
        renderer.target(&texture);
        renderer.draw_color({0, 0, 0, 0});
        renderer.clear();
        renderer.draw_color({ 255, 255, 255, 255 });

        // Generate the random lines
        auto size = arma::conv_to<arma::fmat>::from(window.size());
        arma::fmat A(100, 2, arma::fill::randu);
        arma::fmat B = A * arma::diagmat(size);

        renderer.draw_lines(B);
        zr::render_dispatch rd = renderer.copy();

        // Draw a square
        renderer.target_window();
        renderer.draw_color({ 255, 0, 0, 255 });
        renderer.fill_rects({{x, y, w, h}});
        rd.to_window({500, 0, 600, 900});

        // Copy the lines to the window
        renderer.present();
    }

    std::cout << window.max_size() << std::endl;
    SDL_Quit();
    return 0;
}
