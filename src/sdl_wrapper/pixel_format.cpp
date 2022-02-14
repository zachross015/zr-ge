#include <sdl_wrapper/pixel_format.h>
#include <SDL.h>

namespace zr {

    pixel_format::pixel_format(pixel_format_specifier pf) {

        SDL_PixelFormatEnum format = static_cast<SDL_PixelFormatEnum>(pf);
        // Construct the pixel information
        this->f = pf;
        this->t = static_cast<pixel_type>(SDL_PIXELTYPE(format));
        this->o = static_cast<pixel_order>(SDL_PIXELORDER(format));
        this->l = static_cast<pixel_layout>(SDL_PIXELLAYOUT(format));


        // Save the rest of the variables
        this->bpp = SDL_BITSPERPIXEL(format);
        this->Bpp = SDL_BYTESPERPIXEL(format);
        this->ipfi = SDL_ISPIXELFORMAT_INDEXED(format) == SDL_TRUE;
        this->ipfa = SDL_ISPIXELFORMAT_ALPHA(format) == SDL_TRUE;
        this->ip4cc = SDL_ISPIXELFORMAT_FOURCC(format) == SDL_TRUE;

    }

    pixel_format::~pixel_format() {};

    pixel_format_specifier pixel_format::get_format_specifier() { return f; }

    pixel_type pixel_format::get_type() { return t; }

    pixel_order pixel_format::get_order() { return o; }

    pixel_layout pixel_format::get_layout() { return l; }

    char pixel_format::get_bits_per_pixel() { return bpp; }

    char pixel_format::get_bytes_per_pixel() { return Bpp; }

    bool pixel_format::format_is_indexed() { return ipfi; }

    bool pixel_format::format_is_alpha() { return ipfa; }

    bool pixel_format::format_is_fourcc() { return ip4cc; }

} /* zr */ 
