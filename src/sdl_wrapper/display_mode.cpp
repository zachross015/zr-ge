#include <sdl_wrapper/display_mode.h>
#include <SDL.h>

namespace zr {

    display_mode::display_mode(SDL_DisplayMode dm) : pf(static_cast<pixel_format_specifier>(dm.format)), size<int>(dm.w, dm.h) {

        // Save the rest of the variables
        this->rr = dm.refresh_rate;
        this->dd = dm.driverdata;

    }

    display_mode::~display_mode() {};

    pixel_format display_mode::get_pixel_format() { return pf; }

    int display_mode::get_refresh_rate() { return rr; }

    void* display_mode::get_driver_data() { return dd; }

} /* zr */ 
