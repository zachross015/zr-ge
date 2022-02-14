#include <iostream>
#include <algorithm>
#include <cstdlib>

#include <exceptions.h>
#include <sdl_wrapper/window.h>
#include <sdl_wrapper/renderer.h>
#include <sdl_wrapper/display_mode.h>

#include <SDL.h>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

int main(int argc, char* argv[]) {

    zr::window window = zr::window("Hello", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, { zr::opengl, zr::resizable });
    window.set_title("Hello world");

    zr::renderer renderer = zr::renderer(window, {zr::accelerated});

    int gameover = 0;
    SDL_Event event;
    while(!gameover) {
        if(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    gameover = 1;
                    break;
            }
        }

        renderer.set_draw_color({ 0, 0, 0, 255 });
        renderer.clear();

        renderer.set_draw_color({ 255, 255, 255, 255 });

        // Generate the random lines
        auto size = arma::conv_to<arma::fmat>::from(window.get_size());
        arma::fmat A(100, 2, arma::fill::randu);
        arma::fmat B = A * arma::diagmat(size);

        renderer.draw_lines(B);

        renderer.present();
    }

    std::cout << window.get_max_size() << std::endl;
    SDL_Quit();
    return 0;
}
