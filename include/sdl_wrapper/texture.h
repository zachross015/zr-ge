#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include "renderer.h"
#include "pixel_format.h"
#include "blend_mode.h"
#include "../immutable_size.h"

namespace  zr {

    enum class texture_access {
        static_access = SDL_TEXTUREACCESS_STATIC,
        streaming_access = SDL_TEXTUREACCESS_STREAMING,
        target_access = SDL_TEXTUREACCESS_TARGET
    };


    enum class texture_modulate {
        none = SDL_TEXTUREMODULATE_NONE,
        color = SDL_TEXTUREMODULATE_COLOR,
        alpha = SDL_TEXTUREMODULATE_ALPHA 
    };


    class texture : public immutable_size<int>{
        private:

        pixel_format pf;

        texture_access ta;

        public:

            texture(const renderer& r, const pixel_format_specifier& pf, const texture_access& ta, int w, int h);
            virtual ~texture();

            texture_access get_texture_access();

            char get_alpha();
            void set_alpha(char alpha);

            blend_mode get_blend_mode();
            void set_blend_mode(const blend_mode& bm);
            

            color get_color();
            void set_color(const color& c);

            // TODO: The following still need to be implemented. It might be
            // more useful to separate this class into classes deriving from the
            // different texture access classes since those can not be changed
            // once initialized. This is mainly bc lock/unlock can only be used
            // with streaming access, so it is kind of pointless to include the
            // method for all three.
            //
            // void bind_to_opengl();
            // void unbind_from_opengl();
            // void lock();
            // void unlock();
            //

    };

} /*  zr  */ 

#endif /* TEXTURE_H */  
