#include <cmath>
#include <game-engine/initializer.hpp>

#include "systems.h"


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

    // View for the paddles
    auto view = registry.view<const position, const paddle>();
    view.each([&](const auto &pos, const auto &p) {

        // View for the balls
        auto b_view = registry.view<const position, velocity, const ball>();
        b_view.each([&](const auto &b_pos, auto &b_vel, const auto &b) {

            // Construct bounding rect
            auto rect = ge::basic_rect<float>(pos.x, pos.y, PADDLE_WIDTH, PADDLE_HEIGHT);
            ge::basic_point<float> closest_point;

            // Closest point is defined differently depending on whether we are
            // on the left or right
            if(p.side == paddle_side::left) {
                closest_point = ge::basic_point<float>(b_pos.x - BALL_RADIUS, b_pos.y);
            } else if(p.side == paddle_side::right) {
                closest_point = ge::basic_point<float>(b_pos.x + BALL_RADIUS, b_pos.y);
            }

            // If the rectangle contains the closest point, just negate the
            // velocity. We will probably also need to apply come correction to
            // the ball but that's not included yet.
            if(rect.contains(closest_point)) {
                b_vel.dx *= -1;
            }
        });
    });
}



/** Physics update for keeping the ball entities within the bounding box.
 *
 * @param registry The registry containing the balls.
 */
void keep_balls_in_box(ge::registry &registry) {
    auto view = registry.view<const position, velocity, const ball>();
    view.each([](const auto &pos, auto &vel, const auto &b) {

        // Negate the velocity if the ball tries to go out side the box
        if(pos.y - BALL_RADIUS <= 0 || pos.y + BALL_RADIUS > SCREEN_HEIGHT) {
            vel.dy *= -1;
        }
    });
}


/** Holds the ball in place for the beginning of their lifetime (specified by
 * INITIAL_BALL_PAUSE).
 *
 * @param registry The registry containing the balls.
 */
void hold_balls(ge::registry &registry) {
    auto view = registry.view<position, const velocity, ball>();
    view.each([](auto &pos, const auto &vel, auto &b) {
        if(b.lifetime < INITIAL_BALL_PAUSE) {
            b.lifetime++;
            pos.x -= vel.dx;
            pos.y -= vel.dy;
        }
    });
}
