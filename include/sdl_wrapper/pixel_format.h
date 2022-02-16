#ifndef PIXELS_H
#define PIXELS_H

#include <ostream>
#include <SDL.h>

namespace zr {

    /*! \enum PixelFormat
     *
     *  Enumeration of pixel formats
     */
    enum class pixel_format_specifier { 
        unknown = SDL_PIXELFORMAT_UNKNOWN,
        index_1_lsb = SDL_PIXELFORMAT_INDEX1LSB,
        index_1_msb = SDL_PIXELFORMAT_INDEX1MSB,
        index_4_lsb = SDL_PIXELFORMAT_INDEX4LSB,
        index_4_msb = SDL_PIXELFORMAT_INDEX4MSB,
        index_8 = SDL_PIXELFORMAT_INDEX8,
        rgb_332 = SDL_PIXELFORMAT_RGB332,
        rgb_444 = SDL_PIXELFORMAT_RGB444,
        rgb_555 = SDL_PIXELFORMAT_RGB555,
        bgr_555 = SDL_PIXELFORMAT_BGR555,
        argb_4444 = SDL_PIXELFORMAT_ARGB4444,
        rgba_4444 = SDL_PIXELFORMAT_RGBA4444,
        abgr_4444 = SDL_PIXELFORMAT_ABGR4444,
        bgra_4444 = SDL_PIXELFORMAT_BGRA4444,
        argb_1555 = SDL_PIXELFORMAT_ARGB1555,
        rgba_5551 = SDL_PIXELFORMAT_RGBA5551,
        abgr_1555 = SDL_PIXELFORMAT_ABGR1555,
        bgra_5551 = SDL_PIXELFORMAT_BGRA5551,
        rgb_565 = SDL_PIXELFORMAT_RGB565,
        bgr_565 = SDL_PIXELFORMAT_BGR565,
        rgb_24 = SDL_PIXELFORMAT_RGB24,
        bgr_24 = SDL_PIXELFORMAT_BGR24,
        rgb_888 = SDL_PIXELFORMAT_RGB888,
        rgb_x8888 = SDL_PIXELFORMAT_RGBX8888,
        bgr_888 = SDL_PIXELFORMAT_BGR888,
        bgr_x8888 = SDL_PIXELFORMAT_BGRX8888,
        argb_8888 = SDL_PIXELFORMAT_ARGB8888,
        rgba_8888 = SDL_PIXELFORMAT_RGBA8888,
        abgr_8888 = SDL_PIXELFORMAT_ABGR8888,
        bgra_8888 = SDL_PIXELFORMAT_BGRA8888,
        argb_2101010 = SDL_PIXELFORMAT_ARGB2101010, 
        yv12 = SDL_PIXELFORMAT_YV12,
        iyuv = SDL_PIXELFORMAT_IYUV,
        yuy2 = SDL_PIXELFORMAT_YUY2,
        uyvy = SDL_PIXELFORMAT_UYVY,
        yvyu = SDL_PIXELFORMAT_YVYU,
        nv12 = SDL_PIXELFORMAT_NV12,
        nv21 = SDL_PIXELFORMAT_NV21
    };


    /*! \enum PixelType
     *
     */
    enum class pixel_type { 
        unknown = SDL_PIXELTYPE_UNKNOWN,
        index_1 = SDL_PIXELTYPE_INDEX1,
        index_4 = SDL_PIXELTYPE_INDEX4,
        index_8 = SDL_PIXELTYPE_INDEX8,
        packed_8 = SDL_PIXELTYPE_PACKED8,
        packed_16 = SDL_PIXELTYPE_PACKED16,
        packed_32 = SDL_PIXELTYPE_PACKED32,
        array_u8 = SDL_PIXELTYPE_ARRAYU8,
        array_u16 = SDL_PIXELTYPE_ARRAYU16,
        array_u32 = SDL_PIXELTYPE_ARRAYU32,
        array_f16 = SDL_PIXELTYPE_ARRAYF16,
        array_f32 = SDL_PIXELTYPE_ARRAYF32
    };

    enum class pixel_order {
        bitmap_none = SDL_BITMAPORDER_NONE,
        bitmap_4321 = SDL_BITMAPORDER_4321,
        bitmap_1234 = SDL_BITMAPORDER_1234,
        packed_none = SDL_PACKEDORDER_NONE,
        packed_xrgb = SDL_PACKEDORDER_XRGB,
        packed_rgbx = SDL_PACKEDORDER_RGBX,
        packed_argb = SDL_PACKEDORDER_ARGB,
        packed_rgba = SDL_PACKEDORDER_RGBA,
        packed_xbgr = SDL_PACKEDORDER_XBGR,
        packed_bgrx = SDL_PACKEDORDER_BGRX,
        packed_abgr = SDL_PACKEDORDER_ABGR,
        packed_bgra = SDL_PACKEDORDER_BGRA,
        array_none = SDL_ARRAYORDER_NONE,
        array_rgb = SDL_ARRAYORDER_RGB,
        array_rgba = SDL_ARRAYORDER_RGBA,
        array_argb = SDL_ARRAYORDER_ARGB,
        array_bgr = SDL_ARRAYORDER_BGR,
        array_bgra = SDL_ARRAYORDER_BGRA,
        array_abgr = SDL_ARRAYORDER_ABGR,
    };

    /*! \enum PixelLayout
     *
     *  Detailed description
     */
    enum class pixel_layout { 
        packed_none = SDL_PACKEDLAYOUT_NONE,
        packed_332 = SDL_PACKEDLAYOUT_332,
        packed_4444 = SDL_PACKEDLAYOUT_4444,
        packed_1555 = SDL_PACKEDLAYOUT_1555,
        packed_5551 = SDL_PACKEDLAYOUT_5551,
        packed_565 = SDL_PACKEDLAYOUT_565,
        packed_8888 = SDL_PACKEDLAYOUT_8888,
        packed_2101010 = SDL_PACKEDLAYOUT_2101010,
        packed_1010102 = SDL_PACKEDLAYOUT_1010102
    };


    /** Read only class which provides information on pixel formats and
     * associated values.
     *
     * @todo A great abstraction which will be necessary down the line is
     * converting from a color to a specific pixel_format. pixel_format should
     * be abstract down the line with overrides from the different formats,
     * types, orders, and layouts, with each of those providing methods that
     * perform the automated conversions. Further consideration needs to be done
     * in case for example a new layout comes out. I don't want to deal with
     * hard coding things for that reason.
     *
     */
    class pixel_format {

        private: 

            // Format specifier connected to the underlying type of pixel format
            // values
            pixel_format_specifier f;

            // Pixel type connected to the underlying pixel type
            pixel_type t;

            // Pixel order enumeration connected to the underlying pixel
            // ordering
            pixel_order o;

            // Pixel layout enumeration connected to the underlying pizel layout
            // description.
            pixel_layout l;

            // Bits per pixel
            char bpp;

            // Bytes per pixel
            char Bpp;

            // Is pixel format indexed
            bool ipfi;

            // Is pixel format alpha
            bool ipfa;

            // Is pixel format four cc
            bool ip4cc;

        public:

            /** Constructs the pixel format for quick querys dealing with pixel
             * information.
             *
             * Pixel formats determine a number of things, primarily to do with
             * how textures are colored and how data is translated to the
             * screen. This constructor coagulates all the information dealing
             * with the pixel, allowing for quick access. 
             *
             * @param f The format specifier for this pixel format.
             */
            pixel_format(pixel_format_specifier f);


            /** Deconstructor for the pixel format.
             */
            ~pixel_format();

            /** Format specifier this pixel format was initialized to.
             *
             * @return The format specifier (i.e. the wrapped
             * SDL_PixelFormatEnum)
             */
            pixel_format_specifier get_format_specifier();


            /** Pixel type for this pixel format.
             *
             * Different pixel types specify the size of the data in a pixel
             * array, along with how the information in this array is packed
             * together. E.g. an array pixel type stores pixel information in an
             * array while packed stores them in a singular value.
             *
             * @return The pixel type (i.e. the wrapped SDL_PIXELTYPE macro)
             */
            pixel_type get_type();


            /** Pixel layout specifically for packed pixel formats.
             *
             * Different layouts specify how, within packed pixel formats, how
             * the underlying datatype is structured. E.g. a packed layout with
             * 4444 has 4 bytes of the datatype contributed to each color
             * component, whereas under a layout of 5551, thee first three
             * components get 5 bytes while the last pixel only has one byte.
             *
             */
            pixel_layout get_layout();

            
            /** Pixel ordering for this pixel format.
             *
             * Different pixel layouts specify the order in which different
             * values appear in the pixel structure. E.g. an RGB format has the
             * order as red, green, then blue, while a BGR format has the order
             * blue, green, red.
             *
             * @return The pixel ordering (i.e. the wrapped SDL_PIXELORDER macro)
             */
            pixel_order get_order();


            /** Number of bits per pixel are allowed in this pixel format.
             *
             * @return The number of bits.
             */
            char get_bits_per_pixel();


            /** Number of bytes per pixel are allowed in this format.
             *
             * @return The number of bytes.
             */
            char get_bytes_per_pixel();


            /** Whether or not this format is one of the indexed pixel formats
             * (i.e. reads from a color table).
             *
             * @return True if it is indexed, false otherwise.
             */
            bool format_is_indexed();


            /** Whether this format contains an alpha channel.
             *
             * @return True if this format contains an alpha channel, false
             * otherwise.
             */
            bool format_is_alpha();


            /** Whether this format represents a unique format (e.g. YUV
             * formats)
             *
             * @return True if this format is a unique format, false otherwise.
             */
            bool format_is_fourcc();
    };

} /* zr  */ 

#endif /* PIXELS_H */
