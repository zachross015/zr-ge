#include <util.h>
#include <sdl_wrapper/window.h>
#include <exceptions.h>
#include <type_traits>

namespace zr {

    std::vector<window_state> all_window_states() {
        const window_state all[] = {
            fullscreen,
            fullscreen_desktop,
            opengl,
            vulkan,
            shown,
            hidden,
            borderless,
            resizable,
            minimized,
            maximized,
            mouse_trapped,
            input_focus,
            mouse_focus,
            foreign,
            allow_highdpi,
            mouse_capture,
            always_on_top,
            skip_taskbar,
            utility,
            tooltip,
            popup_menu
        };
        return std::vector<window_state>(all, all + sizeof(all) / sizeof(window_state));
    }


    std::ostream& operator<<(std::ostream& out, const window_state& ws) {
        const char* s = 0;
#define CV(v) case(window_state::v): s = #v; break;
        switch (ws) {
            CV(fullscreen)
                CV(fullscreen_desktop)
                CV(opengl)
                CV(vulkan)
                CV(shown)
                CV(hidden)
                CV(borderless)
                CV(resizable)
                CV(minimized)
                CV(maximized)
                CV(mouse_trapped)
                CV(input_focus)
                CV(mouse_focus)
                CV(foreign)
                CV(allow_highdpi)
                CV(mouse_capture)
                CV(always_on_top)
                CV(skip_taskbar)
                CV(utility)
                CV(tooltip)
                CV(popup_menu)
        }       
#undef CV
        out << s;
        return out;
    }


    window::window(std::string title, int x, int y, int w, int h, int flags) {

        // Initialize the video device if not already initizlied. If an error
        // occurs, handle it.
        if (!SDL_WasInit(SDL_INIT_VIDEO)) {
            if(SDL_Init(SDL_INIT_VIDEO) < 0){
                throw sdl_exception("[Window::Window] Error in initializing video.");
            }
        }

        // On successful video initialization, actuall create the window with the
        // given parameters.
        this->w = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
        if (this->w == NULL) {
            throw sdl_exception("[window::window] Error in creating the window.");
        }
    }


    window::window(std::string title, int x, int y, int w, int h, const std::vector<window_state>& states) {
        // Initialize the video device if not already initizlied. If an error
        // occurs, handle it.
        if (!SDL_WasInit(SDL_INIT_VIDEO)) {
            if(SDL_Init(SDL_INIT_VIDEO) < 0){
                throw sdl_exception("[Window::Window] Error in initializing video.");
            }
        }

        // On successful video initialization, actuall create the window with the
        // given parameters.
        this->w = SDL_CreateWindow(title.c_str(), x, y, w, h, enums_to_flags(states));
        if (this->w == NULL) {
            throw sdl_exception("[window::window] Error in creating the window.");
        }
    }


    window::window(std::string title, int w, int h, const std::vector<window_state>& states) {
        window(title, 
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                w, 
                h, 
                states);
    }


    window::window(int w, int h, const std::vector<window_state>& states) {
        window("Untitled", 
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED, 
                w, 
                h, 
                states);
    }


    window::~window() {
        SDL_DestroyWindow(w);
    }


    void window::show() {
        SDL_ShowWindow(w);
    }


    void window::hide() {
        SDL_HideWindow(w);
    }


    arma::Col<int> window::get_borders_size() {
        int t, l, b, r;
        if(SDL_GetWindowBordersSize(w, &t, &l, &b, &r)) {
            throw sdl_exception("[window::get_borders_size] Error when trying to get the borders size for the window.");
        }
        return {t, l, b, r};
    }


    void window::set_bordered(bool b) {
        SDL_SetWindowBordered(w,  b ? SDL_TRUE : SDL_FALSE);
    }


    int window::get_display_index() {
        int index = SDL_GetWindowDisplayIndex(w);
        if(index < 0) {
            throw sdl_exception("[window::get_display_index] Error in getting window display index.");
        }
        return index;
    }


    display_mode window::get_display_mode() {
        SDL_DisplayMode mode;
        int failure = SDL_GetWindowDisplayMode(w, &mode);
        if(failure) {
            throw sdl_exception("[window::get_display_mode] Error in retrieving the display mode for the current window.");
        }
        return display_mode(mode);
    }


    void window::set_display_mode(display_mode dm) {
        SDL_DisplayMode mode;
        mode.format = static_cast<std::underlying_type<pixel_format>::type>(dm.get_pixel_format());
        mode.w = dm.get_width();
        mode.h = dm.get_height();
        mode.refresh_rate = dm.get_refresh_rate();
        mode.driverdata = dm.get_driver_data();
        int failure = SDL_SetWindowDisplayMode(w, &mode);
        if(failure) {
            throw sdl_exception("[window::set_display_mode] Error when setting the window's display mode.");
        }
    }


    std::vector<window_state> window::get_states() {
        return flags_to_enums(SDL_GetWindowFlags(w), all_window_states());
    }


    bool window::is_mouse_trapped() {
        return SDL_GetWindowGrab(w);
    }


    void window::set_mouse_trapped(bool tf) {
        SDL_SetWindowGrab(w, tf ? SDL_TRUE : SDL_FALSE);
    }


    unsigned int window::get_id() {
        return SDL_GetWindowID(w);
    }

    arma::ivec window::get_max_size() {
        int w, h;
        SDL_GetWindowMaximumSize(this->w, &w, &h);
        return {w, h};
    }


    void window::set_max_size(const arma::ivec& size) {
        SDL_SetWindowMaximumSize(w, size(0), size(1)); 
    }


    arma::ivec window::get_min_size() {
        int w, h;
        SDL_GetWindowMinimumSize(this->w, &w, &h);
        return {w, h};
    }


    void window::set_min_size(const arma::ivec& size) {
        SDL_SetWindowMinimumSize(w, size(0), size(1)); 
    }


    float window::get_opacity() {
        float o;
        int failure = SDL_GetWindowOpacity(w, &o);  
        if(failure) {
            throw sdl_exception("[window::get_window_opacity] Error getting window opacity.");
        }
        return o;
    }


    void window::set_opacity(float o) {
        int failure = SDL_SetWindowOpacity(w, o);  
        if(failure) {
            throw sdl_exception("[window::set_window_opacity] Error setting window opacity. This system may not support alternate window opacities.");
        }
    }

    arma::ivec window::get_pos() {
        int w, h;
        SDL_GetWindowPosition(this->w, &w, &h);
        return {w, h};
    }

    void window::set_pos(const arma::ivec& pos) {
        SDL_SetWindowPosition(w, pos(0), pos(1)); 
    }

    arma::ivec window::get_size() {
        int w, h;
        SDL_GetWindowSize(this->w, &w, &h);
        return {w, h};
    }

    void window::set_size(const arma::ivec& size) {
        SDL_SetWindowSize(w, size(0), size(1)); 
    }


    std::string window::get_title() {
        return std::string(SDL_GetWindowTitle(w));
    }


    void window::set_title(const std::string& s) {
        SDL_SetWindowTitle(w, s.c_str());
    }


    void window::maximize() { SDL_MaximizeWindow(w); }


    void window::minimize() { SDL_MinimizeWindow(w); }


    void window::raise() { SDL_RaiseWindow(w); }


    void window::restore() { SDL_RestoreWindow(w); }


    void window::make_fullscreen(bool with_dr) {
        unsigned int flag = with_dr ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_FULLSCREEN;
        int failure = SDL_SetWindowFullscreen(w, flag);
        if(failure) {
            throw sdl_exception("[window::make_fullscreen] Error making the window fullscreen.");
        }
    }

} /* zr  */ 

