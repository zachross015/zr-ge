#ifndef RENDER_DISPATCH_H
#define RENDER_DISPATCH_H

#include <armadillo>
#include <SDL.h>
#include "renderer.h"
#include "texture.h"

namespace zr {

    /** Class which maintains the state of renders that are meant to be drawn to
     * the screen.  
     *
     * This class is not meant to be intialized publicly, and is only meant to
     * be used by renderer during the `copy` operation. This operation creates a
     * 'copy' of the state of information meant to be copied to some target.
     * Once created, all information is immutable and only serves to provide the
     * mechanism for delivering the stored information either to a destination
     * texture or to the window the given renderer was initalized with.
     */
    class render_dispatch {
        private:

            friend class renderer;

            renderer* r;
            texture* t;
            const arma::Col<int> source_rect;

            render_dispatch(renderer* r, texture* t, const arma::Col<int> source_rect = {});

        public:

            /** Deconstructor for the render dispatch.  */
            virtual ~render_dispatch();


            /** Delivers the state information to the given texture 
             *
             * Fills in the destination rectangle with all the texture
             * information from the source texture and source rectangle
             * (specified in renderer::copy). 
             *
             * @todo Put more checks in for source/destination textures and
             * errors they may produce. 
             * @todo Implement the rectangle functions and replace the values in
             * here.
             *
             * @remark if the source_rect size does not match the
             * destination_rect size, then the source texture will be rescaled
             * to fit the destination size. This rescaling is determined by the
             * texture_scaling_method.
             *
             * @throw sdl_exception An exception that can occur if SDL has an
             * error copying the original texture to the new texture.
             *
             * @param texture A pointer to the texture that the source should be
             * copied to.
             * @param destination_rectangle A specifier for the location and
             * size that the source should be copied to in the destination
             * texture.
             *
             */
            void to(texture* texture, const arma::Col<int>& destination_rectangle = {});



            /** Delivers the state information to the window this renderer was
             * intialized to.
             *
             * Fills in the destination rectangle with all the texture
             * information from the source texture and source rectangle
             * (specified in renderer::copy). 
             *
             * @todo Put more checks in for source/destination textures and
             * errors they may produce. 
             * @todo Implement the rectangle functions and replace the values in
             * here.
             *
             * @remark if the source_rect size does not match the
             * destination_rect size, then the source texture will be rescaled
             * to fit the destination size. This rescaling is determined by the
             * texture_scaling_method.
             *
             * @throw sdl_exception An exception that can occur if SDL has an
             * error copying the original texture to the window.
             *
             * @param destination_rectangle A specifier for the location and
             * size that the source should be copied to in the destination
             * window.
             *
             */
            void to_window(const arma::Col<int>& destination_rectangle = {});
    };

} /* zr  */ 


#endif /* RENDER_DISPATCH_H */
