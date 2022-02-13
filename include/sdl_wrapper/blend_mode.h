#ifndef BLEND_MODE_H
#define BLEND_MODE_H

#include <SDL.h>
#include <vector>
#include <ostream>

namespace zr {

    /*! \enum blend_mode
     *
     *  An enumeration of blend modes used by the renderer and drawing operations. 
     */
    enum class blend_mode {  
        none = SDL_BLENDMODE_NONE,
        blend = SDL_BLENDMODE_BLEND,
        add = SDL_BLENDMODE_ADD,
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
