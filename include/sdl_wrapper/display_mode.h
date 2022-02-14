#ifndef DISPLAY_MODE_H
#define DISPLAY_MODE_H

#include "pixel_format.h"
#include "../size.h"

namespace zr {

    // Read only class which delivers information about the display mode.
    // Wrapper for https://wiki.libsdl.org/SDL_DisplayMode
    // @todo Make not read only and make a struct. Windows can be altered by changing display mode
    // information, which right now is impossible to do.
    class display_mode : public size<int> {
        private:

            // Information that can be retrieved given a pixel format. Display
            // mode is unlikely to change, and so these values will be
            // relatively constant once init.
            pixel_format pf;

            // Refresh Rate
            int rr;

            // Excess driver data. 
            void* dd;

        public:

            /** Constructor for the display mode struture. Contains the
             * information for how the window or display is being...displayed.
             *
             * @param dm The SDL_DisplayMode.
             */
            display_mode(SDL_DisplayMode dm);


            /** Deconstructor for this class.
             */
            virtual ~display_mode();


            /** Gets the pixel format associated with this display.
             *
             * @return The pixel format this display uses.
             */
            pixel_format get_pixel_format();


            /** Gets the refresh rate of this display.
             *
             * @return An integer with this display's refresh rate.
             */
            int get_refresh_rate();


            /** Get the driver data associated with this window. This should not
             * be tampered with outside of using this to initialize other
             * windows.
             *
             * @return void* Containing the driver data.
             */
            void* get_driver_data();
    };

} /* zr */ 


#endif /* DISPLAY_MODE_H */
