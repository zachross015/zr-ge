#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include "renderer.h"
#include "pixel_format.h"
#include "blend_mode.h"
#include "renderable.h"
#include "../underlying_types.h"

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


    /** Underlying class abstraction for a texture. The three derived class are
     * notably static_texture, streaming_texture, and target_texture which all
     * have different access rights depending on the use case.
     *
     * @todo Consider removing the public constructor in favor of a constructor
     * inside 'renderer'. I'm still unclear whether or not the texture needs to
     * be connected to a renderer, but it definitely needs a renderer for
     * construction. 
     * @todo Consider how to include the texture scaling methods.
     */
    class texture : public size_i<int> {
        private:

            friend class renderer;
            friend class render_drawer;

            /** The underlying pixel format for this texture */
            pixel_format pf;


            /** The initalized access level for this texture. */
            texture_access ta;


            /** Underlying SDL structure for the texture */
            SDL_Texture* t = NULL;

            /** Auxiliary Functions */

            /** Initalization is a bitch and a half, but specifically parents
             * HAVE to be initalized prior to any functions being run. This
             * auxiliary function investigates the variables needed to
             * initalized the parents when using the copy constructor (i.e. gets
             * the size of the underlying texture prior to init so this texture
             * can be init to the right size).
             *
             * @throw sdl_exception An error which can occur when SDL attempts
             * to query the texture.
             *
             * @param te The texture to get the size from
             * @return The width and height in column vector format of the given
             * texture
             */
            arma::Col<int> pre_init_size(SDL_Texture *te);

        protected:

            /** Copy constructor for the texture class which just retrieves all
             * its information from the underlying SDL_Texture.
             *
             * @throw sdl_exception An error which can occur when SDL attempts
             * to query the texture.
             *
             */
            texture(SDL_Texture* te);

            /** Hidden constructor for the class of textures. This creates a texture
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
             * @param size The size of the texture (w, h).
             * @param texture_access The level of access this texture should
             * have (which helps to specify its purpose). Defaults to
             * texture_access::target_access as we assume most operations where
             * you manually initalize this will be to draw to it.
             * @param pixel_format_specifier The pixel format for which this
             * texture should take on. Defaults to ARGB 8888 as this is fairly
             * standard and usually need not be messed with.
             */
            texture(const renderer& renderer, 
                    const arma::Col<int>& size,
                    const texture_access& texture_access = texture_access::target_access, 
                    const pixel_format_specifier& pixel_format_specifier = pixel_format_specifier::rgba_8888
                   );

        public:

            /** Texture deconstructor.
            */
            virtual ~texture();


            /** Get the alpha channel overlay for this texture.
             *
             * @throw sdl_exception The error is unspecified by SDL.
             *
             * @return the alpha level between 0 and 255.
             */
            unsigned char alpha();


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
            void alpha(unsigned char alpha);


            /** Get the blend mode used for drawing operations.
             * 
             * @throw sdl_exception Error when retrieving the blend mode.
             *
             * @return Associate blend mode.
             */
            blend_mode mode();


            /** Set the blend mode used for drawing operations.
             * 
             * @throw sdl_exception Error when retrieving the blend mode.
             *
             * @param bm Associate blend mode.
             */
            void mode(const blend_mode& bm);


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
            const color& color_overlay();


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
            void color_overlay(const color& c);


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
            const pixel_format& format();


            /** Returns the texture access this texture was initialized to.
             *
             * The texture access can not be changed after initialization.
             *
             * @return The texture access level for this texture.
             */
            const texture_access& access();



    };


    /** Class of textures that can be used as a render target. These textures
     * can be drawn to by renderer and otherwise mutated.
     */
    class target_texture : public texture {

        public:

            /** Constructor for the class of target textures. This creates a
             * texture for which the given renderer can render to.
             *
             * @throw sdl_exception An exception can occur either if the
             * rendering context passed was inactive, if the pixel format is
             * unsupported, or if one of the size arguments is out of bounds.
             *
             * @param renderer The renderer that will be used to create this
             * texture. 
             * @param size The size of the texture (w, h).
             * @param pixel_format_specifier The pixel format for which this
             * texture should take on. Defaults to ARGB 8888 as this is fairly
             * standard and usually need not be messed with.
             */
            target_texture(const renderer& renderer, 
                    const arma::Col<int>& size,
                    const pixel_format_specifier& pcf = pixel_format_specifier::rgba_8888
                   ) : texture(renderer, size, texture_access::target_access, pcf) {};
    
    };


    /** Class of textures that involve infrequent changes and are not lockable.
     */
    class static_texture : public texture {

        public:
            /** Constructor for the static class of textures. This creates a texture
             * for which the given renderer can render to.
             *
             * @throw sdl_exception An exception can occur either if the
             * rendering context passed was inactive, if the pixel foramt is
             * unsupported, or if one of the size arguments is out of bounds.
             *
             * @param renderer The renderer that will be used to create this
             * texture. 
             * @param size The size of the texture (w, h).
             * @param pixel_format_specifier The pixel format for which this
             * texture should take on. Defaults to ARGB 8888 as this is fairly
             * standard and usually need not be messed with.
             */
            static_texture(const renderer& renderer, 
                    const arma::Col<int>& size,
                    const pixel_format_specifier& pcf = pixel_format_specifier::rgba_8888
                   ) : texture(renderer, size, texture_access::static_access, pcf) {};
    
    };


    /** Class of textures that are changed frequently and have a locking
     * mechanism for such an occasion.
     *
     * @todo implement locking mechanism
     *
     */
    class streaming_texture : public texture {

        public:
            /** Constructor for the streaming class of textures. This creates a texture
             * for which the given renderer can render to.
             *
             * @throw sdl_exception An exception can occur either if the
             * rendering context passed was inactive, if the pixel foramt is
             * unsupported, or if one of the size arguments is out of bounds.
             *
             * @param renderer The renderer that will be used to create this
             * texture. 
             * @param size The size of the texture (w, h).
             * @param pixel_format_specifier The pixel format for which this
             * texture should take on. Defaults to ARGB 8888 as this is fairly
             * standard and usually need not be messed with.
             */
            streaming_texture(const renderer& renderer, 
                    const arma::Col<int>& size,
                    const pixel_format_specifier& pcf = pixel_format_specifier::rgba_8888
                   ) : texture(renderer, size, texture_access::streaming_access, pcf) {};
    

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
