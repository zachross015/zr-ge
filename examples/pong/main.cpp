#include <iostream>
#include <game-engine/initializer.hpp>


#include "pong.h"


int main(int, char**) {

    // Create a window and an associated renderer
    ge::window window;
    window.set_size({SCREEN_WIDTH, SCREEN_HEIGHT});

    ge::renderer renderer = window.make_renderer();

    window.show();

    // Build registry with paddles
    ge::registry registry;
    build_paddle(registry, {PADDLE_WIDTH, (window.height() - PADDLE_HEIGHT) / 2}, left);
    build_paddle(registry, {window.width() - (2 * PADDLE_WIDTH), (window.height() - PADDLE_HEIGHT) / 2}, right);
    build_new_ball(registry);


    bool running = true;
    while (running) {
        ge::event_handler handler;
        while (handler.poll()) {
            if (handler.is(ge::event_type::quit)) {
                running = false;
                break;
            }         
        }

        // Event bind updates
        bind_paddle_movement_keys(registry, left, ge::keycodes::w, ge::keycodes::s); 
        bind_paddle_movement_keys(registry, right, ge::keycodes::up, ge::keycodes::down); 

        // Physics updates
        hold_balls(registry);
        update_movables(registry);
        keep_balls_in_box(registry);
        handle_collisions(registry);

        // Drawing updates
        renderer.set_color(ge::color(0, 0, 0));
        renderer.clear();

        draw_paddles(registry, renderer);
        draw_balls(registry, renderer);

        // Apply our draw calls to the render target (the window)
        renderer.present();
    }

    window.hide();

    return 0;
}
