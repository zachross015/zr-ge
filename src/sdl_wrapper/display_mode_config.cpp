#include <sdl_wrapper/display_mode_config.h>
#include <SDL.h>

namespace zr {

    display_mode_config::display_mode_config(SDL_DisplayMode dm) : pf(static_cast<pixel_format_specifier>(dm.format)), size<int>(dm.w, dm.h) {

        // Save the rest of the variables
        this->rr = dm.refresh_rate;
        this->dd = dm.driverdata;

    }

    display_mode_config::~display_mode_config() {};

    pixel_format display_mode_config::get_pixel_format() { return pf; }

    int display_mode_config::get_refresh_rate() { return rr; }

    void display_mode_config::set_refresh_rate(int r) { rr = r; }

    void* display_mode_config::get_driver_data() { return dd; }

    void display_mode_config::set_driver_data(void* d) { dd = d; }

} /* zr */ 
