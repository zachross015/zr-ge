#ifndef PIXELS_H
#define PIXELS_H

#include <ostream>
#include <SDL.h>

namespace zr {

    /*! \enum PixelFormat
     *
     *  Enumeration of pixel formats
     */
    enum class pixel_format { 
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


} /* zr  */ 

#endif /* PIXELS_H */
