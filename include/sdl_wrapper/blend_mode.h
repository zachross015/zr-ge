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
     */
    enum class blend_mode {  


        /** No blending 
         *
         * destinationRGBA = sourceRGBA
         */
        none = SDL_BLENDMODE_NONE,


        /** Alpha blending 
         *
         * destinationRGB = (sourceRGB * sourceA) + (destinationRGB * (1 - sourceA)
         * destinationA = sourceA + (destinationA * (1 - sourceA))
         */
        blend = SDL_BLENDMODE_BLEND,


        /** Additive blending
         *
         * destinationRGB = (sourceRGB * sourceA) + destination RGB
         * destinationA = destinationA
         */
        add = SDL_BLENDMODE_ADD,


        /** Color modulate
         *
         * destinationRB = sourceRGB * destinationRGB
         * destinationA = destinationA
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
