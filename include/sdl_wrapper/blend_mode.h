#ifndef BLEND_MODE_H
#define BLEND_MODE_H

/** @file 
 *
 * @todo SDL_BlendMode is an actual class defined by a combination of custom
 * blend mode quanities as defined in
 * https://wiki.libsdl.org/SDL_ComposeCustomBlendMode.
 * The code should eventuall be extended to include enums for blend factos and
 * blend operations, then the ability to return the custom blend mode from
 * those. Until then, we'll just do boiler plate.
 * */

#include <SDL.h>
#include <vector>
#include <ostream>

namespace zr {

    /** An enumeration of blend modes used by the renderer and drawing
     * operations. Additional values may be obtained using
     * SDL_ComposeCustomBlendMode() @todo Replace SDL_ComposeCustomBlendMode lol
     *
     * Additional explanations provided by: 
     * https://www.gamedev.net/forums/topic/690797-blend-mode-in-sdl/5349982/
     */
    enum class blend_mode {  


        /** No blending. 
         * The `blend_mode::none` is basically "overwrite" - when you write a
         * pixel to the location that you already wrote a pixel to, the pixel
         * underneath is completely replaced with the new one.
         *
         * `destinationRGBA = sourceRGBA`
         */
        none = SDL_BLENDMODE_NONE,


        /** Alpha blending. 
         * The `blend_mode::blend` instead gives you a mixture of the old pixel and the
         * new one, based on how large the 'A' or 'alpha' value of the new pixel
         * is. If 'A' is 1, you just see the new pixel (like with the _NONE
         * mode), if 'A' is 0, the old pixel is left in place, and values
         * between 0 and 1 will be a blend between the 2.
         *
         * `destinationRGB = (sourceRGB * sourceA) + (destinationRGB * (1 - sourceA))`
         *
         * `destinationA = sourceA + (destinationA * (1 - sourceA))`
         */
        blend = SDL_BLENDMODE_BLEND,


        /** Additive blending.
         * `blend_mode::add` is like `blend_mode::blend` except the new pixel's
         * colour (scaled by the new pixel's alpha) is 'added' to the old pixel.
         * This means the pixel can only get brighter, based on how bright the
         * new pixel is. This might be useful for bright particles like
         * electrical sparks or fire.
         *
         * `destinationRGB = (sourceRGB * sourceA) + destinationRGB`
         *
         * `destinationA = destinationA`
         */
        add = SDL_BLENDMODE_ADD,


        /** Color modulate
         * `blend_mode::mod` is like `blend_mode::add`, except the pixels can
         * only get darker, based on how dark the new pixel is. You might use
         * this for dark particles like smoke or flying debris.
         *
         * `destinationRGB = sourceRGB * destinationRGB`
         *
         * `destinationA = destinationA`
         */
        mod = SDL_BLENDMODE_MOD
    };

    /** Retrieves the list of all possible blend modes for enumeration
     * purposes.
     *
     * @return std::vector<blend_mode> consisting of all possible render
     * states.
     */
    std::vector<blend_mode> all_blend_modes();

    /** Ostream operator overload for the render_state enumerator.
     *
     * @param  out The ostream
     * @param  ws  The render state to be printed out
     * @return     The outputted render state.
     */
    std::ostream& operator<<(std::ostream& out, const blend_mode& ws);

}

#endif
