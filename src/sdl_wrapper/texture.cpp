#include <sdl_wrapper/texture.h>

namespace zr {

    texture::texture(const renderer& r, 
                     const arma::Col<int>& size,
                     const texture_access& ta, 
                     const pixel_format_specifier& pfs)
        : size_i<int>(size),
          pf(pixel_format(pfs)),
          ta(ta) {
        this->t = SDL_CreateTexture(r.r, 
                              static_cast<Uint32>(pfs),
                              static_cast<int>(ta),
                              width(), 
                              height());
        if (t == NULL) {
            throw sdl_exception("[texture::texture] Either the rendering context was inactive, the format was unsupported, or one of the size arguments was out of bounds.");
        }

        // Set the default blend mode to alpha blending since this seems like
        // the expected behavior.
        mode(blend_mode::blend);
    };

    arma::Col<int> texture::pre_init_size(SDL_Texture* t) {
        Uint32 format;
        int w, h, a;
        if(SDL_QueryTexture(t, &format, &a, &w, &h)) {
            throw sdl_exception("[texture::pre_init_size] Error occurred when attempting to query the given texture. It's possible the texture was never initalized.");
        }
        return {w, h}; 
    }

    texture::texture(SDL_Texture* t) : t(t), size_i<int>(pre_init_size(t)), pf(pixel_format_specifier::unknown), ta(texture_access::static_access) {
        Uint32 format;
        int w, h, a;
        if(SDL_QueryTexture(t, &format, &a, &w, &h)) {
            throw sdl_exception("[texture::texture] Error occurred when attempting to query the given texture. It's possible the texture was never initalized.");
        }
        this->pf = pixel_format(static_cast<pixel_format_specifier>(format));
        this->ta = static_cast<texture_access>(a);
    }


    texture::~texture() {
        SDL_DestroyTexture(t);
    }


    blend_mode texture::mode() {
        SDL_BlendMode bm;
        int failure = SDL_GetTextureBlendMode(t, &bm);
        if (failure) {
            throw sdl_exception("[texture::blend_mode] Error retrieving this texture's blend mode.");
        }
        return static_cast<blend_mode>(bm);
    }


    void texture::mode(const blend_mode& bm) {
        SDL_BlendMode m = static_cast<SDL_BlendMode>(bm);
        if(SDL_SetTextureBlendMode(t, m)) {
            throw sdl_exception("[texture::blend] Error setting the blend mode.");
        }
    }

    unsigned char texture::alpha() {
        unsigned char mod;
        if(SDL_GetTextureAlphaMod(t, &mod)) {
            throw sdl_exception("[texture::alpha] Error getting the alpha value.");
        }
        return mod;
    }

    void texture::alpha(unsigned char alpha) {
        if(SDL_SetTextureAlphaMod(t, alpha)) {
            throw sdl_exception("[texture::alpha] Error getting the alpha value.");
        }
    }

    const pixel_format& texture::format() { return pf; }

    const texture_access& texture::access() { return ta; }
    
} /* zr  */ 
