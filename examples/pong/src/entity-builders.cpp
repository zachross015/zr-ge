#include <cmath>
#include <game-engine/initializer.hpp>

#include <entity-builders.h>


void build_paddle(ge::registry &registry, position p, paddle_side side) {
    const auto entity = registry.create();
    registry.emplace<position>(entity, p.x, p.y);
    registry.emplace<paddle>(entity, side);
    registry.emplace<velocity>(entity, 0.0, 0.0);
}


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


void build_initial_registry(ge::registry &registry) {
    build_paddle(registry, {PADDLE_WIDTH, (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2}, left);
    build_paddle(registry, {SCREEN_WIDTH - (2 * PADDLE_WIDTH), (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2}, right);
    build_new_ball(registry);
}
