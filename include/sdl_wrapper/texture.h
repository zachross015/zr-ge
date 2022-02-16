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


    enum class texture_scaling_method {
        nearest_pixel_sampling,
        linear_filtering,
        anisotropic_filtering
    };


    /**
     *
     * @todo Consider removing the public constructor in favor of a constructor
     * inside 'renderer'. I'm still unclear whether or not the texture needs to
     * be connected to a renderer, but it definitely needs a renderer for
     * construction. 
     * @todo Consider how to include the texture scaling methods.
     * @todo Consider separating into several classes for dealing with the
     * different access methods. This may be important since streaming textures
     * have different methods while target_access is required for the renderer
     * to be able to draw to this.
     */
    class texture : public immutable_size<int> {
        private:

        friend class renderer;
        friend class render_dispatch;

        /** The underlying pixel format for this texture */
        pixel_format pf;


        /** The initalized access level for this texture. */
        texture_access ta;


        /** Underlying SDL structure for the texture */
        SDL_Texture* t;

        public:

            /** Constructor for the class of textures. This creates a texture
             * for which the given renderer can render to.
             *
             * @todo Firstly a question: can a texture only be drawn to by the
             * renderer that created it? If so, we should keep track of all the
             * textures a renderer is connected to and vice versa. That way,
             * whenever we clean up a renderer, all child textures will be
             * destroyed, and when a texture is destroyed the renderer can be
             * notified promptly.
             *
             * @throw sdl_exception An exception can occur either if the
             * rendering context passed was inactive, if the pixel foramt is
             * unsupported, or if one of the size arguments is out of bounds.
             *
             * @param renderer The renderer that will be used to create this
             * texture. 
             * @param pixel_format_specifier The pixel format for which this
             * texture should take on.
             * @param texture_access The level of access this texture should
             * have (which helps to specify its purpose.)
             * @param size The size of the texture (w, h).
             */
            texture(const renderer& renderer, 
                    const pixel_format_specifier& pixel_format_specifier, 
                    const texture_access& texture_access, 
                    const arma::Col<int>& size);


            /** Texture deconstructor.
             */
            virtual ~texture();


            /** Get the alpha channel overlay for this texture.
             *
             * @throw sdl_exception The error is unspecified by SDL.
             *
             * @return the alpha level between 0 and 255.
             */
            unsigned char get_alpha();


            /** Set an additional alpha value multiplied into render copy
             * operations.
             *
             * @remark When this texture is rendered, during the copy operation
             * the source alpha value is modulated by this alpha value according
             * to the following formula:
             *
             * sourceA = sourceA * (alpha / 255)
             *
             * Alpha modulation is not always supported by the renderer.
             *
             * @throw sdl_exception if the modulation is not supported by the
             * renderer.
             *
             * @param alpha The alpha value to set this texture to.
             */
            void set_alpha(unsigned char alpha);


            /** Get the blend mode used for drawing operations.
             * 
             * @throw sdl_exception Error when retrieving the blend mode.
             *
             * @return Associate blend mode.
             */
            blend_mode get_blend_mode();


            /** Set the blend mode used for drawing operations.
             * 
             * @throw sdl_exception Error when retrieving the blend mode.
             *
             * @param bm Associate blend mode.
             */
            void set_blend_mode(const blend_mode& bm);
            

            /** Get the additional color value multiplied into render copy
             * operations.
             *
             * @todo This could be made more meaningful if we potentially
             * derived it from the color class. That way, instead of having a
             * separate value for setting the color overlay and the alpha
             * overlay, we would just manipulate the separate components of the
             * texture (e.g. just mess with the red values.)
             *
             * @todo Implement this
             */
            color get_color_overlay();


            /** Set an additional color value multiplied into render copy
             * operations.
             *
             * @todo Implement this.
             *
             * @remark When this texture is rendered, during the copy operation
             * the source alpha value is modulated by this alpha value according
             * to the following formula:
             *
             * sourceRGB = sourceRGB * (color / 255)
             *
             * Color modulation is not always supported by the renderer.
             *
             * @param c The color to set this color overlay to.
             */
            void set_color_overlay(const color& c);


            /** Returns the pixel format this texture was initialized to.  
             *
             * The pixel format can not be changed after initialization...or can
             * it?
             *
             * @todo Could there be a way to change pixel formats? Is that worth
             * even considering?
             *
             * @return The pixel format this texture was initialized to.
             */
            const pixel_format& get_pixel_format();


            /** Returns the texture access this texture was initialized to.
             *
             * The texture access can not be changed after initialization.
             *
             * @return The texture access level for this texture.
             */
            const texture_access& get_texture_access();
            

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
