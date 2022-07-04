#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <cmath>
#include <game-engine/initializer.hpp>

#include "components.h"
#include "config.h"


/** Updates all objects containing a position and a velocity.
 *
 * @param registry Registry containing all the elements with both a position and
 * a velocity.
 */
void update_movables(ge::registry &registry); 


/** Handles the collisions between the ball and the paddle
 *
 *  @TODO May have to maintain a position buffer for the ball
 *
 *  @param registry Registry containing the paddles and balls
 */
void handle_collisions(ge::registry &registry); 



/** Physics update for keeping the ball entities within the bounding box.
 *
 * @param registry The registry containing the balls.
 */
void keep_balls_in_box(ge::registry &registry); 


/** Holds the ball in place for the beginning of their lifetime (specified by
 * INITIAL_BALL_PAUSE).
 *
 * @param registry The registry containing the balls.
 */
void hold_baby_balls(ge::registry &registry); 


/** Determines if the ball has exited either the right or left boundary. If so,
 * gives a point to the corresponding side, deletes the ball, and adds a new
 * one.
 *
 * @param regitry The registry containing the game elements.
 */
void handle_ball_exit(ge::registry &registry);

#endif
