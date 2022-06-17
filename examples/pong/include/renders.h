#ifndef RENDERS_H
#define RENDERS_H

#include <game-engine/initializer.hpp>

#include "components.h"
#include "config.h"


/** Draws all the paddle entities to the renderer 
 *
 * @param registry The registry containing all the paddle entities
 * @param renderer The renderer to draw the paddles to
 */
void draw_paddles(ge::registry &registry, ge::renderer &renderer); 


/** Draws all the ball entities to the renderer 
 *
 * @param registry The registry containing all the ball entities
 * @param renderer The renderer to draw the balls to
 */
void draw_balls(ge::registry &registry, ge::renderer &renderer); 

#endif
