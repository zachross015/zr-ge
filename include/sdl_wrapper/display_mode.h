#ifndef DISPLAY_MODE_H
#define DISPLAY_MODE_H

#include "pixels.h"

namespace zr {

    // Read only class which delivers information about the display mode.
    // Wrapper for https://wiki.libsdl.org/SDL_DisplayMode
    class display_mode {
        private:

            // Underlying pixel format value
            unsigned int uv;

            // Information that can be retrieved given a pixel format. Display
            // mode is unlikely to change, and so these values will be
            // relatively constant once init.
            pixel_format pf;
            pixel_type pt;
            pixel_order po;
            pixel_layout pl;

            // Width 
            int w;

            // Height
            int h;

            // Refresh Rate
            int rr;

            // Excess driver data. 
            void* dd;

        public:
            display_mode(SDL_DisplayMode dm);
            virtual ~display_mode();

            pixel_format get_pixel_format();
            pixel_type get_pixel_type();
            pixel_order get_pixel_order();
            pixel_layout get_pixel_layout();

            int get_width();
            int get_height();
            int get_refresh_rate();
            void* get_driver_data();

            int get_bits_per_pixel();
            int get_bytes_per_pixel();
            bool is_format_indexed();
            bool is_format_alpha();
            bool is_format_fourcc();
    };

} /* zr */ 


#endif /* DISPLAY_MODE_H */
