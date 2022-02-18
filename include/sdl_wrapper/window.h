#ifndef WINDOW_H
#define WINDOW_H
 
#include <string>
#include <SDL.h>
#include <vector>
#include <armadillo>
#include "display_mode_config.h"

namespace zr {

    /*! \enum class window_state
     *
     *  An enumeration of window states
     */
    enum window_state {
        fullscreen = SDL_WINDOW_FULLSCREEN, 
        fullscreen_desktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
        opengl = SDL_WINDOW_OPENGL,
        vulkan = SDL_WINDOW_VULKAN,
        shown = SDL_WINDOW_SHOWN,
        hidden = SDL_WINDOW_HIDDEN,
        borderless = SDL_WINDOW_BORDERLESS,
        resizable = SDL_WINDOW_RESIZABLE,
        minimized = SDL_WINDOW_MINIMIZED,
        maximized = SDL_WINDOW_MAXIMIZED,
        mouse_trapped = SDL_WINDOW_INPUT_GRABBED,
        input_focus = SDL_WINDOW_INPUT_FOCUS,
        mouse_focus = SDL_WINDOW_MOUSE_FOCUS,
        foreign = SDL_WINDOW_FOREIGN,
        allow_highdpi = SDL_WINDOW_ALLOW_HIGHDPI,
        mouse_capture = SDL_WINDOW_MOUSE_CAPTURE,
        always_on_top = SDL_WINDOW_ALWAYS_ON_TOP,
        skip_taskbar = SDL_WINDOW_SKIP_TASKBAR,
        utility = SDL_WINDOW_UTILITY,
        tooltip = SDL_WINDOW_TOOLTIP,
        popup_menu = SDL_WINDOW_POPUP_MENU
    };


    /** Retrieves the list of all possible window states for enumeration
     * purposes.
     *
     * @return std::vector<window_state> consisting of all possible window
     * states.
     */
    std::vector<window_state> all_window_states();


    /** Ostream operator overload for the window_state enumerator.
     *
     * @param  out The ostream
     * @param  ws  The window state to be printed out
     * @return     The outputted window state.
     */
    std::ostream& operator<<(std::ostream& out, const window_state& ws);


    /** Window
     *
     * @todo For a speed benefit down the line, it may be worthwile to consider
     * storing all the get/set variables and returing constant references to
     * them. This way, we aren't reinitializing things constantly.
     *
     */
    class window : public mutable_size<int> {
        private:

            SDL_Window* w;    
            friend class renderer;


        public:

            /** Support for SDL intialization using stronger typing. 
             *
             * @param title  The title that should appear on the window.
             * @param x      The x coordinate the window should appear on the screen
             * @param y      The y coordinate the window should appear on the screen
             * @param width  The width of the given window (in pixels)
             * @param height The height of the given window (in pixels)
             * @param states The list of window states to apply to this window.
             */
            window(std::string title, 
                   int x,
                   int y,
                   int width, 
                   int height, 
                   const std::vector<window_state>& states = {});


            /** Support for SDL intialization using stronger typing and defaults
             * for the x and y positions.
             *
             * @param title  The title that should appear on the window.
             * @param width  The width of the given window (in pixels)
             * @param height The height of the given window (in pixels)
             * @param states The list of window states to apply to this window.
             */
            window(std::string title, 
                   int width, 
                   int height, 
                   const std::vector<window_state>& states = {});


            /** Support for SDL intialization using stronger typing and defaults
             * for the x and y positions along with the title.
             *
             * @param width  The width of the given window (in pixels)
             * @param height The height of the given window (in pixels)
             * @param states The list of window states to apply to this window.
             */
            window(int width, 
                   int height, 
                   const std::vector<window_state>& states = {});


            /** Default deconstruction of a window object
            */
            virtual ~window();


            /** Shows the current window.
            */
            void show();


            /** Hides the current window.
            */
            void hide();


            /** Get the size of a window's borders (decorations) around the
             * client area.
             *
             * @return 4d column vector containing the borders with order (top,
             * left, bottom, right);
             */
            arma::Col<int> borders_size();


            /** Set the border state of the window.
             *
             * @param b True if the window should have a border, false
             * otherwise.
             */
            void bordered(bool b);


            /** Get the index of the display associated with this window.
             *
             * @throw sdl_exception
             *
             * @return Index of the display.
             */
            int display_index();


            /** Query the display mode to use when a window is visible at
             * fullscreen.
             *
             * @throw sdl_exception
             *
             * @return A display_mode_config structure filled in with the fullscreen
             * display mode
             */
            display_mode_config display_mode();


            /** Set the display mode to use when a window is visible at
             * fullscreen.
             *
             * @remark Only affects the display mode used when the window is in
             * fullscreen. Otherwise, window::size() should be used instead.
             *
             * @throw sdl_exception
             *
             * @return A display_mode_config structure filled in with the fullscreen
             * display mode
             */
            void display_mode(display_mode_config dm);


            /** Retrieves the list of states the current window is subject to.
             *
             * @return List of window states the current window has.
             */
            std::vector<window_state> states();


            /** Determines if the mouse is confined to this window.
             *
             * @return true if the mouse is confined to this window, false
             * otherwise.
             */
            bool is_mouse_trapped();


            /** Determines if the mouse is confined to this window.
             *
             * @return true if the mouse is confined to this window, false
             * otherwise.
             */
            void mouse_trapped(bool tf);


            /** Confines the mouse to the screen.
             */
            void trap_mouse() { mouse_trapped(true); }


            /** Releases the mouse from the screen.
             */
            void release_mouse() { mouse_trapped(false); }


            /** Retrieves this windows identifier.
             *
             * @return Identifier associated with this window.
             */
            unsigned int id();


            /** Gets the maximum size the window is allowed to grow to.
             *
             * @return row vector containing the maximum size of the window.
             */
            arma::ivec max_size();


            /** Sets the maximum size of the window
             *
             * @param size Row vector containing the preferred maximum sizing.
             */
            void max_size(const arma::ivec& size);


            /** Gets the minimum size the window is allowed to grow to.
             *
             * @return row vector containing the minimum size of the window.
             */
            arma::ivec min_size();


            /** Sets the minimum size of the window
             *
             * @param size Row vector containing the preferred minimum sizing.
             */
            void min_size(const arma::ivec& size);

            
            /** Gets the opacity of this window. Takes on a value between 0.0
             * (transparent) and 1.0 (opaque).
             *
             * @remark If transparency isn't supported on this platform, the
             * opacity will always be reported as 1.0f without error.
             *
             * @throw sdl_exception Error that may when retrieving the opacity,
             * possibly due to a bad sdl window configuration.
             *
             * @return Window opacity
             */
            float opacity();


            /** Sets the opacity of this window. Should be a value between 0.0
             * (transparent) and 1.0 (opaque).
             *
             * @param o The opacity to set this window to.
             *
             * @throw sdl_exception Error that may occur if the OS doesn't
             * support alternate opacities.
             */
            void opacity(float o);


            /** Gets the window's position.
             *
             * @return Row vector containing the window's position (x in 0 and y
             * in 1).
             */
            arma::ivec pos();


            /** Sets the window's position.
             *
             * @param pos Row vector containing the window's position (x in 0 and y
             * in 1).
             */
            void pos(const arma::ivec& pos);


            /** Gets the window's width.
             *
             * @return Col vector containing the window's width (w in 0 and h
             * in 1).
             */
            virtual const int& width() override;


            /** Sets the window's width.
             *
             * @param width Col vector containing the window's width (w in 0 and h
             * in 1).
             */
            virtual void width(const int& width) override;


            /** Gets the window's height.
             *
             * @return Col vector containing the window's height (w in 0 and h
             * in 1).
             */
            virtual const int& height() override;


            /** Sets the window's height.
             *
             * @param height Col vector containing the window's height (w in 0 and h
             * in 1).
             */
            virtual void height(const int& height) override;


            /** Gets the window's size.
             *
             * @return Col vector containing the window's size (w in 0 and h
             * in 1).
             */
            virtual const arma::Col<int>& size() override;


            /** Sets the window's size.
             *
             * @param size Col vector containing the window's size (w in 0 and h
             * in 1).
             */
            virtual void size(const arma::Col<int>& size) override;


            /** Gets the window's current title.
             *
             * @return The window's title.
             */
            std::string title();


            /** Sets the window's current title.
             *
             * @param title The window's title.
             */
            void title(const std::string& title);


            /** Makes the window as large as possible.
             */
            void maximize();


            /** Minimizes the current window to an iconic representation.
             */
            void minimize();


            /** Raise a window above other windows and set the input focus.
             */
            void raise();

            
            /** Restore the size and position of a minimized or maximized
             * window.
             */
            void restore();


            /** Makes the current window fullscreen with the option to do either
             * "real" fullscreen or "fake" fullscreen that just takes the size
             * of the desktop.
             *
             * @param with_dr True for "fake" fullscreen, "false" for real
             * fullscreen.
             */
            void make_fullscreen(bool fake = false);


    };
} /* zr */ 


#endif /* WINDOW_H */
