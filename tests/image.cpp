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
    
    float size;
    zr::color color{255, 255, 255, 255};
    zr::pos_m<int> pos;

    square(float s): size(s) {};

    void render(zr::renderer* r) {
        r->draw_color(color);
        r->fill_rects({pos.x(), pos.y(), size, size});
    }
};



// TODO: Need to combine the rendering architecture with ECS. It should be a
// prerequisite that if a component is to be rendered, it must at least have
// both a position and renderable. Otherwise, how would it be rendered? Or like
// how else would we see it lol.
//
// I think what we NEED to do is pass the position as one parameter of
// the render function. That way, objects won't have to store this information
// and the transform can be managed separately. That, and it can be up to the
// renderable object how its positioning is specified.
//
// After more research, it seems like we should be able to pass the renderer as
// a source of truth to any object that inherits the renderable trait (or at
// least we should be able to request it) and so this may be the way to go.

int main(int argc, char* argv[]) {

    zr::window window = zr::window("Hello", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, { zr::opengl, zr::resizable });
    zr::renderer renderer = zr::renderer(window, {zr::accelerated});
    zr::image image = zr::image(&renderer, "../resources/1267209.jpg");

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
                square s(size);
                int coloring = ((i + j) % 2) * 255;
                s.color = {coloring, coloring, coloring, 255};
                s.set_pos({i * size, j * size});
                renderer.render(&s);
            }
        }

        // Copy image to window
        renderer.copy(&image, {0, 0, 500, 500}, {0, 0, 500, 500});

        // Copy the lines to the window
        renderer.present();
    }

    std::cout << window.max_size() << std::endl;

    IMG_Quit();
    SDL_Quit();
    return 0;
}
