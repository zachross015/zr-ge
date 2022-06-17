#include <game-engine/initializer.hpp>

#include "renders.h"


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
        auto rect = ge::basic_rect<float>();
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
    view.each([&](const auto &pos, const auto &b) {
        auto point = ge::basic_point<float>(pos.x, pos.y);
        renderer.set_color(ge::color(255, 255, 255));
        renderer.fill_circle(point, BALL_RADIUS);
    });
}
