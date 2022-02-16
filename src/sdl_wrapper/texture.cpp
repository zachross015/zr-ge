#include <sdl_wrapper/texture.h>

namespace zr {

    texture::texture(const renderer& r, 
                     const pixel_format_specifier& pfs, 
                     const texture_access& ta, 
                     const arma::Col<int>& size) 
        : immutable_size<int>(size),
          pf(pixel_format(pfs)),
          ta(ta) {
        this->t = SDL_CreateTexture(r.r, 
                              static_cast<Uint32>(pfs),
                              static_cast<int>(ta),
                              get_width(), 
                              get_height());
        if (t == NULL) {
            throw sdl_exception("[texture::texture] Either the rendering context was inactive, the format was unsupported, or one of the size arguments was out of bounds.");
        }
    };


    texture::~texture() {
        SDL_DestroyTexture(t);
    }


    blend_mode texture::get_blend_mode() {
        SDL_BlendMode bm;
        int failure = SDL_GetTextureBlendMode(t, &bm);
        if (failure) {
            throw sdl_exception("[texture::get_blend_mode] Error retrieving this texture's blend mode.");
        }
        return static_cast<blend_mode>(bm);
    }


    void texture::set_blend_mode(const blend_mode& bm) {
        SDL_BlendMode mode = static_cast<SDL_BlendMode>(bm);
        if(SDL_SetTextureBlendMode(t, mode)) {
            throw sdl_exception("[texture::set_blend_mode] Error setting the blend mode.");
        }
    }

    unsigned char texture::get_alpha() {
        unsigned char mod;
        if(SDL_GetTextureAlphaMod(t, &mod)) {
            throw sdl_exception("[texture::get_alpha] Error getting the alpha value.");
        }
        return mod;
    }

    void texture::set_alpha(unsigned char alpha) {
        if(SDL_SetTextureAlphaMod(t, alpha)) {
            throw sdl_exception("[texture::get_alpha] Error getting the alpha value.");
        }
    }

    const pixel_format& texture::get_pixel_format() { return pf; }

    const texture_access& texture::get_texture_access() { return ta; }
    
} /* zr  */ 
