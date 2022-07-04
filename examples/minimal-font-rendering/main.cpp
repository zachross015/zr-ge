#include <game-engine.hpp>

#define FONT "../examples/minimal-font-rendering/resources/fonts/main-font.ttf" // Place the file containing your font here
 
int main(int, char**) {
 
    // Load the window and renderer.
    ge::window wind;
    ge::renderer ren = wind.make_renderer();
 
    // Load the font from a file.
    const ge::font fnt(FONT, 40); 
 
    // Create the text texture.
    auto txt = ren.make_texture(fnt.render_blended("Hello world!", ge::colors::white));
    
    // Show the window.
    wind.show();
 
    bool running = true;
    while (running) {
        ge::event_handler handler;
        while (handler.poll()) {
            if (handler.is(ge::event_type::quit)) {
                running = false;
                break;
            }
        }
 
        // Clear our render target with an arbitrary color
        ren.clear_with(ge::colors::black);
 
        // Render the text
        ren.render(txt, ge::fpoint{0.0, 0.0});
 
        // Apply our draw calls to the render target (the window)
        ren.present();
    }
 
    wind.hide();
 
    return 0;
}
