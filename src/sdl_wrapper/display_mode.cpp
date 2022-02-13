#include <sdl_wrapper/display_mode.h>
#include <SDL.h>

namespace zr {

    display_mode::display_mode(SDL_DisplayMode dm) {

        uv = dm.format;

        // Construct the pixel information
        this->pf = static_cast<pixel_format>(dm.format);
        this->pt = static_cast<pixel_type>(SDL_PIXELTYPE(dm.format));
        this->po = static_cast<pixel_order>(SDL_PIXELORDER(dm.format));
        this->pl = static_cast<pixel_layout>(SDL_PIXELLAYOUT(dm.format));


        // Save the rest of the variables
        this->w = dm.w;
        this->h = dm.h;
        this->rr = dm.refresh_rate;
        this->dd = dm.driverdata;

    }

    display_mode::~display_mode() {};

    pixel_format display_mode::get_pixel_format() { return pf; }

    pixel_type display_mode::get_pixel_type() { return pt; }

    pixel_order display_mode::get_pixel_order() { return po; }

    pixel_layout display_mode::get_pixel_layout() { return pl; }

    int display_mode::get_width() { return w; }

    int display_mode::get_height() { return h; }

    int display_mode::get_refresh_rate() { return rr; }

    void* display_mode::get_driver_data() { return dd; }

    int display_mode::get_bits_per_pixel() { return SDL_BITSPERPIXEL(uv); }

    int display_mode::get_bytes_per_pixel() { return SDL_BYTESPERPIXEL(uv); }

    bool display_mode::is_format_indexed() { return SDL_ISPIXELFORMAT_INDEXED(uv); }

    bool display_mode::is_format_alpha() { return SDL_ISPIXELFORMAT_ALPHA(uv); }

    bool display_mode::is_format_fourcc() { return SDL_ISPIXELFORMAT_FOURCC(uv); }

} /* zr */ 
