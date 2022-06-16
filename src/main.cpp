#include <iostream>
#include <game-engine/initializer.hpp>

#define PADDLE_WIDTH  20
#define PADDLE_HEIGHT 100
#define PADDLE_SPEED  10.0

#define BALL_RADIUS 10.0
#define BALL_SPEED  1.0

#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT 1000

/// Component for dictating entity position
struct position {
    double x, y;
};


/// Component for dictating entity velocity
struct velocity {
    double dx, dy;
};


/// Enumeration for the different sides a pong paddle can be on
enum paddle_side {
    left, right
};


/// Component for dictating which side the pong paddle is on
struct paddle {
    paddle_side side;
};


/// Ball component, pretty self explanatory.
struct ball {};


/** Moves the paddles in the registry based on which side it is on and what keys
 * are being pressed.
 *
 * @param registry Reference to the registry containing the paddle entities
 * @param side     The side of the paddle we should be moving
 * @param up       The key code for the button which sends the paddle up
 * @param down     The key code for the button which sends the paddle down
 */
void bind_paddle_movement_keys(ge::registry &registry, paddle_side side, ge::key_code up, ge::key_code down) {

    // Get the keyboard so we can determine inputs
    auto ke = ge::keyboard();

    // Get the view and construct lambda function
    auto view = registry.view<const position, velocity, const paddle>();
    view.each([=](const auto &pos, auto &vel, const auto &p) {
        if(p.side == side) {
            vel.dy = 0.0;
            if(ke.is_pressed(up) && pos.y >= 0.0) {
                vel.dy -= PADDLE_SPEED;
            }
            if(ke.is_pressed(down) && pos.y + PADDLE_HEIGHT < SCREEN_HEIGHT) {
                vel.dy += PADDLE_SPEED;
            }
        }
    });
}


/** Builds the paddle entities and places them in the registry.
 *
 * @param registry The registry to place the paddle in 
 * @param p        The position of the paddle on the screen
 * @param side     Indicator for which side this paddle is on
 */
void build_paddle(ge::registry &registry, position p, paddle_side side) {
    const auto entity = registry.create();
    registry.emplace<position>(entity, p.x, p.y);
    registry.emplace<paddle>(entity, side);
    registry.emplace<velocity>(entity, 0.0, 0.0);
}


/** Builds the ball entities and places them in the registry.
 *
 * Automatically geters the ball on the screen.
 *
 * @param registry The registry to place the ball in 
 */
void build_ball(ge::registry &registry) {
    const auto entity = registry.create();
    registry.emplace<position>(entity, (SCREEN_WIDTH - BALL_RADIUS) / 2, (SCREEN_HEIGHT - BALL_RADIUS) / 2);
    registry.emplace<ball>(entity);

    // Generate random x,y directions and normalize
    double dx = ge::rand::get(-1.0, 1.0) * BALL_SPEED;
    double dy = ge::rand::get(-1.0, 1.0) * BALL_SPEED;
    registry.emplace<velocity>(entity, dx, dy);
}


/** Draws all the paddle entities to the renderer 
 *
 * @param registry The registry containing all the paddle entities
 * @param renderer The renderer to draw the paddles to
 */
void draw_paddles(ge::registry &registry, ge::renderer &renderer) {
    auto view = registry.view<const position, const paddle>();
    for(auto entity: view) {

        // Get variables
        auto &pos = view.get<const position>(entity);

        // Build Rectangle
        auto rect = ge::basic_rect<double>();
        rect.set_x(pos.x);
        rect.set_y(pos.y);
        rect.set_width(PADDLE_WIDTH);
        rect.set_height(PADDLE_HEIGHT);

        // Display rectangle
        renderer.set_color(ge::color(255, 255, 255));
        renderer.fill_rect(rect);
    }
}


/** Draws all the ball entities to the renderer 
 *
 * @param registry The registry containing all the ball entities
 * @param renderer The renderer to draw the balls to
 */
void draw_balls(ge::registry &registry, ge::renderer &renderer) {
    auto view = registry.view<const position, const ball>();
    view.each([&](const auto &pos) {
        auto point = ge::basic_point<double>(pos.x, pos.y);
        renderer.set_color(ge::color(255, 255, 255));
        renderer.fill_circle(point, BALL_RADIUS);
    });
}


/** Updates all objects containing a position and a velocity.
 *
 * @param registry Registry containing all the elements with both a position and
 * a velocity.
 */
void update_movables(ge::registry &registry) {
    auto view = registry.view<position, const velocity>();
    view.each([](auto &pos, const auto &vel) {
        pos.x += vel.dx;
        pos.y += vel.dy;
    });
}


/** Handles the collisions between the ball and the paddle
 *
 *  @TODO May have to maintain a position buffer for the ball
 *
 *  @param registry Registry containing the paddles and balls
 */
void handle_collisions(ge::registry &registry) {
    auto view = registry.view<const position, const paddle>();
    view.each([&](const auto &pos, const auto &p) {
        auto b_view = registry.view<const position, velocity, const ball>();
        b_view.each([&](const auto &b_pos, auto &b_vel) {
                // TODO: THis
        });
    });
}


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
    build_ball(registry);


    bool running = true;
    while (running) {
        ge::event_handler handler;
        while (handler.poll()) {
            if (handler.is(ge::event_type::quit)) {
                running = false;
                break;
            }         
        }

        bind_paddle_movement_keys(registry, left, ge::keycodes::w, ge::keycodes::s); 
        bind_paddle_movement_keys(registry, right, ge::keycodes::up, ge::keycodes::down); 

        update_movables(registry);

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
