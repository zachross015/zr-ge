#include <iostream>
#include <game-engine.hpp>


#include "pong.h"


int main(int, char**) {

    // Create a window and an associated renderer
    ge::window window;
    window.set_size({SCREEN_WIDTH, SCREEN_HEIGHT});
    ge::renderer renderer = window.make_renderer();
    window.show();

    // Build registry with paddles
    ge::registry registry;
    build_initial_registry(registry);

    // Create the font resource
    ge::font main_font(FONT_DIR "/main-font.ttf", FONT_SIZE);
    main_font.set_bold(true);
    auto text = renderer.make_texture(main_font.render_blended("hello world", ge::colors::white));


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

        // Systems updates
        update_movables(registry);
        hold_baby_balls(registry);
        keep_balls_in_box(registry);
        handle_collisions(registry);
        handle_ball_exit(registry);

        // Drawing updates
        renderer.set_color(ge::color(0, 0, 0));
        renderer.clear();
        draw_paddles(registry, renderer);
        draw_balls(registry, renderer);

        // Draw text
        renderer.render(text, ge::fpoint(0.0, 0.0));

        // Apply our draw calls to the render target (the window)
        renderer.present();
    }

    window.hide();

    return 0;
}
