#include <game-engine/initializer.hpp>

#include "keybinds.h"


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
