#ifndef KEYBINDS_H
#define KEYBINDS_H

#include <game-engine/initializer.hpp>

#include "components.h"
#include "config.h"


/** Moves the paddles in the registry based on which side it is on and what keys
 * are being pressed.
 *
 * @param registry Reference to the registry containing the paddle entities
 * @param side     The side of the paddle we should be moving
 * @param up       The key code for the button which sends the paddle up
 * @param down     The key code for the button which sends the paddle down
 */
void bind_paddle_movement_keys(ge::registry &registry, paddle_side side, ge::key_code up, ge::key_code down); 

#endif
