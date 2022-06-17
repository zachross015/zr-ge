#include <cmath>
#include <game-engine/initializer.hpp>

#include <entity-builders.h>


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
void build_new_ball(ge::registry &registry) {
    const auto entity = registry.create();
    registry.emplace<position>(entity, (SCREEN_WIDTH - BALL_RADIUS) / 2, (SCREEN_HEIGHT - BALL_RADIUS) / 2);
    registry.emplace<ball>(entity);

    // Generate random x,y directions and normalize
    float dx = ge::rand::get(-1.0, 1.0) * BALL_SPEED;
    float dy = ge::rand::get(-1.0, 1.0) * BALL_SPEED;
    if(abs(dx) < abs(dy)) {
        float temp = dx;
        dx = dy;
        dy = temp;
    }
    registry.emplace<velocity>(entity, dx, dy);
}
