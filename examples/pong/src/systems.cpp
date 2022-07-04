#include <iostream>
#include <cmath>
#include <game-engine/initializer.hpp>

#include "systems.h"
#include "entity-builders.h"


void update_movables(ge::registry &registry) {
    auto view = registry.view<position, const velocity>();
    view.each([](auto &pos, const auto &vel) {
        pos.x += vel.dx;
        pos.y += vel.dy;
    });
}


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



void keep_balls_in_box(ge::registry &registry) {

    // View for the balls
    auto view = registry.view<const position, velocity, const ball>();
    view.each([](const auto &pos, auto &vel, const auto &b) {

        // Negate the velocity if the ball tries to go out side the box
        if(pos.y - BALL_RADIUS <= 0 || pos.y + BALL_RADIUS > SCREEN_HEIGHT) {
            vel.dy *= -1;
        }
    });
}


void hold_baby_balls(ge::registry &registry) {
    
    // View containing the balls in registry
    auto view = registry.view<position, const velocity, ball>();
    view.each([](auto &pos, const auto &vel, auto &b) {

        // Balls are held in place for the duration of the INITIAL_BALL_PAUSE by
        // negating the velocity updates that occur in the `update_movables`
        // call (happens in the main game loop.)
        if(b.lifetime < INITIAL_BALL_PAUSE) {
            b.lifetime++;
            pos.x -= vel.dx;
            pos.y -= vel.dy;
        }
    });
}


void handle_ball_exit(ge::registry &registry) {

    // Iterate through balls
    auto view = registry.view<const position, const ball>();
    view.each([&](const auto ball_entity, const auto &pos, const auto &b) {

        // Iterate through the paddles
        auto p_view = registry.view<paddle>();
        p_view.each([&](auto &p) {

            // Determine if ball has exited.
            bool left_point = pos.x + BALL_RADIUS >= SCREEN_WIDTH && p.side == paddle_side::left;
            bool right_point = pos.x - BALL_RADIUS <= 0 && p.side == paddle_side::right;

            // Only one of the two conditions will be true, which partitions
            // the event space into left and right paddle. So p will always
            // contain the winning paddle, so we can just increment that
            // entity's score.
            if(left_point || right_point) {
                p.score++; 
                registry.destroy(ball_entity);
                build_new_ball(registry);
            }
        });
    });
}
