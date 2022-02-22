#ifndef IMAGE_H
#define IMAGE_H

#include "texture.h"

#include <string>

#include <SDL.h>
#include <SDL_image.h>

namespace zr {

    /** Class for loading images from storage and converting them into textures
     * for dispay.
     *
     * @todo Do we need a whole class for this? Or could this just be included
     * in the texture class?
     */
    class image : public texture {

        private:
            
            /** Auxiliary functions */

            /** The default initalizer for classes doesn't allow for us to
             * initalize the texture prior to initalizing parent's. Because of
             * this, this helper function deciphers the values we need from our
             * constructor prior to initalizing the parents. This can be thought
             * of as the prior initalizer.
             */
            SDL_Texture* texture_from_path(renderer* r, std::string path);

        public:

            /** Constructor for the image class.
             *
             * Constructs the image by loading it from the given filepath and
             * connecting the image to the given renderer.
             *
             * Images can be loaded as long as they suit one of the required
             * formats:
             *   - TGA
             *   - BMP
             *   - PNM
             *   - XPM
             *   - XCF
             *   - PCX
             *   - GIF
             *   - JPG
             *   - TIF 
             *   - LBM
             *   - PNG
             *
             * @throw sdl_img_exception Exception which can occur when loading
             * an image from a given file path. More details will be given by
             * SDL_image.
             * @throw sdl_exception Exception which can occur when attemtping to
             * load a texture from a given surface. More details will be given
             * by SDL.
             *
             * @param renderer The renderer to connect this image to.
             * @param path The file path to the desired image.
             */
            image(renderer* renderer, std::string path);
    };

} /* zr  */ 

#endif /* IMAGE_H */        
