#ifndef ENTITY_BUILDERS_H
#define ENTITY_BUILDERS_H

#include <cmath>
#include <game-engine/initializer.hpp>

#include "components.h"
#include "config.h"


/** Builds the paddle entities and places them in the registry.
 *
 * @param registry The registry to place the paddle in 
 * @param p        The position of the paddle on the screen
 * @param side     Indicator for which side this paddle is on
 */
void build_paddle(ge::registry &registry, position p, paddle_side side); 


/** Builds the ball entities and places them in the registry.
 *
 * Automatically geters the ball on the screen.
 *
 * @param registry The registry to place the ball in 
 */
void build_new_ball(ge::registry &registry); 

#endif
