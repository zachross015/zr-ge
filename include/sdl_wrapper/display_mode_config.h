#ifndef DISPLAY_MODE_H
#define DISPLAY_MODE_H

#include "pixel_format.h"
#include "../mutable_size.h"

namespace zr {

    // Class which delivers information about the display mode.
    // Wrapper for https://wiki.libsdl.org/SDL_DisplayMode
    class display_mode_config : public mutable_size<int> {
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
            display_mode_config(SDL_DisplayMode dm);


            /** Deconstructor for this class.
             */
            virtual ~display_mode_config();


            /** Gets the pixel format associated with this display.
             *
             * @return The pixel format this display uses.
             */
            const pixel_format& format() const;


            /** Sets the pixel format associated with this display.
             *
             * @return The pixel format this display uses.
             */
            void format(const pixel_format& f);



            /** Gets the refresh rate of this display.
             *
             * @return An integer with this display's refresh rate.
             */
            int refresh_rate();


            /** Sets the refresh rate of this display configuration.
             *
             * @param refresh_rate An integer with this display's refresh rate.
             */
            void refresh_rate(int refresh_rate);


            /** Get the driver data associated with this window. This should not
             * be tampered with outside of using this to initialize other
             * windows.
             *
             * @return void* Containing the driver data.
             */
            void* driver_data();


            /** Set the driver data associated with this window. This should not
             * be tampered with outside of using this to initialize other
             * windows and unless you know what you're doing.
             *
             * @param driver_data void* Containing the driver data.
             */
            void driver_data(void* driver_data);
    };

} /* zr */ 


#endif /* DISPLAY_MODE_H */
