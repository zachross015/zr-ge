#include <sdl_wrapper/image.h>
#include <exceptions.h>

namespace zr {

    SDL_Texture* image::texture_from_path(renderer* r, std::string path) {
        
        // Load the image library
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

        // Initialize storage variables and load image in
        SDL_Texture* t = NULL;
        SDL_Surface* s = IMG_Load(path.c_str());
        if(s == NULL) {
            throw sdl_img_exception("[image::image] Error loading the file from the given path.");
        }

        // Create the texture from the loaded image
        t = SDL_CreateTextureFromSurface(r->r, s);
        if(t == NULL) {
            throw sdl_exception("[image::image] Error creating a texture from the given image.");
        }

        // Free the loaded image
        SDL_FreeSurface(s);

        // Return the texture
        return t;
    }

    image::image(renderer* r, std::string path) : texture(texture_from_path(r, path)) { }

} /* zr  */ 
