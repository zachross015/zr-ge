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

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600


class test_drawing : public zr::renderable {
    public: 
        void render(zr::renderer* r) { 
            r->draw_color({0, 0, 0, 255});
            r->fill_rects({{500, 500, 100, 500}}); 
        }
};

struct square : public zr::renderable {

    zr::pos_m<float> pos;
    float size;
    zr::color color{255, 255, 255, 255};

    square(zr::pos_m<float> pos, float s): pos(pos), size(s) {};

    void render(zr::renderer*r) {
        r->draw_color(color);
        r->fill_rects({pos.x(), pos.y(), size, size});
    }
};

int main(int argc, char* argv[]) {

    zr::window window = zr::window("Hello", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, { zr::opengl, zr::resizable });
    zr::renderer renderer = zr::renderer(window, {zr::accelerated});

    int gameover = 0;
    SDL_Event event;

    float size = 100;

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

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                square s({i * size, j * size}, size);
                int coloring = ((i + j) % 2) * 255;
                s.color = {coloring, coloring, coloring, 255};
                renderer.render(&s);
            }
        }

        // Copy the lines to the window
        renderer.present();
    }

    std::cout << window.max_size() << std::endl;

    IMG_Quit();
    SDL_Quit();
    return 0;
}
