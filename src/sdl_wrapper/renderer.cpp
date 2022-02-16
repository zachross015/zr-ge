#include <sdl_wrapper/renderer.h>
#include <sdl_wrapper/texture.h>
#include <exceptions.h>
#include <util.h>
#include <exception>
#include <sdl_wrapper/render_dispatch.h>

namespace zr {

    std::vector<renderer_state> all_renderer_states() {
        const renderer_state all[] = {
            software,
            accelerated,
            present_vsync,
            target_texture
        };
        return std::vector<renderer_state>(all, all + sizeof(all) / sizeof(renderer_state));
    }


    std::ostream& operator<<(std::ostream& out, const renderer_state& ws) {
        const char* s = 0;
#define CV(v) case(renderer_state::v): s = #v; break;
        switch (ws) {
            CV(software)
                CV(accelerated)
                CV(present_vsync)
                CV(target_texture)
        }       
#undef CV
        out << s;
        return out;
    }


    renderer::renderer(const window& w, const std::vector<renderer_state>& rs, int i) {
        r = SDL_CreateRenderer(w.w, i, enums_to_flags(rs));
        if(r == NULL) {
            throw sdl_exception("[renderer::renderer] Error loading in renderer.");
        }
    }


    renderer::~renderer() {

        // Clean up target 
        target = 0;
        delete target;

        // Clean up renderer
        SDL_DestroyRenderer(r);
    }


    blend_mode renderer::get_blend_mode() {
        SDL_BlendMode bm;
        int failure = SDL_GetRenderDrawBlendMode(r, &bm);
        if (failure) {
            throw sdl_exception("[renderer::get_blend_mode] Error retrieving this renderer's blend mode.");
        }
        return static_cast<blend_mode>(bm);
    }


    void renderer::set_blend_mode(const blend_mode& bm) {
        SDL_BlendMode mode = static_cast<SDL_BlendMode>(bm);
        if(SDL_SetRenderDrawBlendMode(r, mode)) {
            throw sdl_exception("[renderer::set_blend_mode] Error setting the blend mode.");
        }
    }


    color renderer::get_draw_color() {
        color c;
        if(SDL_GetRenderDrawColor(r, &c.r, &c.g, &c.b, &c.a)) {
            throw sdl_exception("[renderer::get_draw_color] Error getting the draw color.");
        }
        return c;
    }


    void renderer::set_draw_color(const color& c) {
        if(SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a)) {
            throw sdl_exception("[renderer::set_draw_color] Error setting the draw color.");
        }
    }


    arma::Col<int> renderer::get_output_size() {
        int w, h;
        if(SDL_GetRendererOutputSize(r, &w, &h)) {
            throw sdl_exception("[renderer::get_output_size]");
        }
        return {w, h};
    }


    void renderer::clear() {
        if(SDL_RenderClear(r)) {
            throw sdl_exception("[renderer::clear]"); 
        }
    } 


    void renderer::draw_lines(const arma::Mat<float>& lines) {
        if (lines.n_rows < 2 || lines.n_cols != 2) {
            throw input_exception("[renderer::draw_lines] Incorrect dimensions of input were provided. (Necessary: >=2 x 2 | Provided: " + std::to_string(lines.n_rows) + " x " + std::to_string(lines.n_cols) + ")");
        }
        SDL_FPoint points[lines.n_rows];
        for(int i = 0; i < lines.n_rows; i++) {
            points[i] = { lines(i, 0), lines(i, 1) };
        }
        if(SDL_RenderDrawLinesF(r, points, lines.n_rows)) {
            throw sdl_exception("[renderer::draw_lines] TODO: Make this more descriptive (2)."); 
        }
    }


    void renderer::draw_points(const arma::Mat<float>& points) {
        if (points.n_rows < 1 || points.n_cols != 2) {
            throw input_exception("[renderer::draw_points] Incorrect dimensions of input were provided. (Necessary: >=1 x 2 | Provided: " + std::to_string(points.n_rows) + " x " + std::to_string(points.n_cols) + ")");
        }
        SDL_FPoint sdl_points[points.n_rows];
        for(int i = 0; i < points.n_rows; i++) {
            sdl_points[i] = { points(i, 0), points(i, 1) };
        }
        if(SDL_RenderDrawPointsF(r, sdl_points, points.n_rows)) {
            throw sdl_exception("[renderer::draw_points] TODO: Make this more descriptive (2)."); 
        }
    }


    void renderer::draw_rects(const arma::Mat<float>& rects) {
        if (rects.n_rows < 1 || rects.n_cols != 4) {
            throw input_exception("[renderer::draw_rects] Incorrect dimensions of input were provided. (Necessary: >=1 x 4 | Provided: " + std::to_string(rects.n_rows) + " x " + std::to_string(rects.n_cols) + ")");
        }
        SDL_FRect sdl_rects[rects.n_rows];
        for(int i = 0; i < rects.n_rows; i++) {
            sdl_rects[i] = { rects(i, 0), rects(i, 1), rects(i, 2), rects(i, 3) };
        }
        if(SDL_RenderDrawRectsF(r, sdl_rects, rects.n_rows)) {
            throw sdl_exception("[renderer::draw_rects] TODO: Make this more descriptive (2)."); 
        }

    }


    void renderer::fill_rects(const arma::Mat<float>& rects) {
        if (rects.n_rows < 1 || rects.n_cols != 4) {
            throw input_exception("[renderer::fill_rects] Incorrect dimensions of input were provided. (Necessary: >=1 x 4 | Provided: " + std::to_string(rects.n_rows) + " x " + std::to_string(rects.n_cols) + ")");
        }
        SDL_FRect sdl_rects[rects.n_rows];
        for(int i = 0; i < rects.n_rows; i++) {
            sdl_rects[i] = { rects(i, 0), rects(i, 1), rects(i, 2), rects(i, 3) };
        }
        if(SDL_RenderFillRectsF(r, sdl_rects, rects.n_rows)) {
            throw sdl_exception("[renderer::draw_rects] TODO: Make this more descriptive (2)."); 
        }

    }


    void renderer::present() {
        SDL_RenderPresent(r); 
    }


    arma::Col<int> renderer::get_clip_rect() {
        SDL_Rect rect;
        SDL_RenderGetClipRect(r, &rect);
        return { rect.x, rect.y, rect.w, rect.h };
    }


    void renderer::set_clip_rect(const arma::Col<int>& cr) {
        SDL_Rect rect = { cr(0), cr(1), cr(2), cr(3) };
        if(SDL_RenderSetClipRect(r, &rect)) {
            throw sdl_exception("[renderer::set_clip_rect]");
        }
    }


    bool renderer::integer_scales_are_forced() {
        return SDL_RenderGetIntegerScale(r) == SDL_TRUE;
    }


    void renderer::set_force_integer_scales(bool tf) {
        if(SDL_RenderSetIntegerScale(r, tf ? SDL_TRUE : SDL_FALSE)) {
            throw sdl_exception("[renderer::set_force_integer_scales]");
        }
    }


    arma::Col<int> renderer::get_logical_size() {
        int w, h;
        SDL_RenderGetLogicalSize(r, &w, &h);
        return {w, h};
    }


    void renderer::set_logical_size(const arma::Col<int>& ls) {
        if(SDL_RenderSetLogicalSize(r, ls(0), ls(1))) {
            throw sdl_exception("[renderer::set_logical_size]");
        }
    }


    arma::Col<float> renderer::get_scale() {
        float x, y;
        SDL_RenderGetScale(r, &x, &y); 
        return {x, y};
    }


    void renderer::set_scale(const arma::Col<float>& s) {
        if(SDL_RenderSetScale(r, s(0), s(1))) {
            throw sdl_exception("[renderer::set_scale]");
        }
    }


    arma::Col<int> renderer::get_viewport() {
        SDL_Rect rect;
        SDL_RenderGetViewport(r, &rect);
        return {rect.x, rect.y, rect.w, rect.h};
    }


    void renderer::set_viewport(const arma::Col<int>& vp) {
        SDL_Rect rect = { vp(0), vp(1), vp(2), vp(3) }; 
        if(SDL_RenderSetViewport(r, &rect)) {
            throw sdl_exception("[renderer::set_viewport]");
        }
    }


    bool renderer::is_clipping_enabled() {
        return SDL_RenderIsClipEnabled(r) == SDL_TRUE;
    }


    bool renderer::supports_targets() {
        return SDL_RenderTargetSupported(r) == SDL_TRUE;
    }


    render_dispatch renderer::copy(const arma::Col<int>& source_rect) {
        if(target == NULL) throw input_exception("[renderer::copy] This function should only be called when a texture is being targeted, since a copy can not perform a copy when the target is the window. The default behavior under this condition is the renderer will draw to the window unconditionally.");
        return render_dispatch(this, target, source_rect);
    }


    void renderer::set_target_window() {
        this->target = NULL;
        SDL_SetRenderTarget(r, NULL); 
    }


    void renderer::set_target(texture* t) {
        if(t == NULL || t == nullptr) {
            throw input_exception("[renderer::set_target] Attempted to pass a null pointer as a target to the renderer. Make sure the texture has been initialized before sending it.");
        } else if(t->get_texture_access() != texture_access::target_access) {
            throw input_exception("[renderer::set_target] Attempted to pass a texture with an invalid access type. Must have texture_access::target_access.");
        }

        this->target = t;
        SDL_SetRenderTarget(r, t->t); 
    }


    texture* renderer::get_target() {
        return target;
    }

} /* zr  */ 
