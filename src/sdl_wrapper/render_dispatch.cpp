#include <sdl_wrapper/render_dispatch.h>
#include <sdl_wrapper/renderer.h>
#include <sdl_wrapper/texture.h>


#include <iostream>

namespace zr {

    render_dispatch::render_dispatch(renderer* r, texture* t, const arma::Col<int> source_rect) : r(r), t(t), source_rect(source_rect) {};


    render_dispatch::~render_dispatch() {
        r = 0;
        delete r;

        t = 0;
        delete t;
    }


    void render_dispatch::to(texture* t, const arma::Col<int>& dst_rect) {

        // Initialize source and destination rectangles to NULL. We do this
        // since NULL is the default case, in which the entire of the source
        // texture is copied into the entire of the destination location and is
        // stretched where necessary. 
        SDL_Rect *src = NULL, *dst = NULL;

        if(!source_rect.is_empty()) {
            src = new SDL_Rect();
            src->x = source_rect(0);
            src->y = source_rect(1);
            src->w = source_rect(2);
            src->h = source_rect(3);
        }

        if(!dst_rect.is_empty()) {
            dst = new SDL_Rect();
            dst->x = dst_rect(0);
            dst->y = dst_rect(1);
            dst->w = dst_rect(2);
            dst->h = dst_rect(3);
        }

        // We want the render dispatch to preserve the ordering of calls. E.g.
        // If we have the following sequence
        //
        // render_dispatch dispatch_1 = renderer.copy();
        // renderer.target(another_texture);
        // dispatch_1.to(a_third_texture);
        //
        // we have to make sure that the dispatch copies its original contents
        // when the renderer was copied rather than the new target, making the
        // renderer relatively agnostic of its dispatchs. To do this, we save
        // and restore the current target of the renderer.
        texture* temp = r->target();
        r->target(t);
        int failure = SDL_RenderCopy(r->r, this->t->t, src, dst);

        // Don't want to try and set the target to NULL if there was no target!
        if(temp != NULL) r->target(temp);

        // Clean up before potential failures.
        delete src;
        delete dst;
        temp = 0;
        delete temp;

        if(failure) {
            throw sdl_exception("[render_dispatch::to] Error in copying from one texture to another.");
        }


    }


    void render_dispatch::to_window(const arma::Col<int>& dst_rect) {

        // Initialize source and destination rectangles to NULL. We do this
        // since NULL is the default case, in which the entire of the source
        // texture is copied into the entire of the destination location and is
        // stretched where necessary. 
        SDL_Rect *src = NULL, *dst = NULL;

        if(!source_rect.is_empty()) {
            src = new SDL_Rect();
            src->x = source_rect(0);
            src->y = source_rect(1);
            src->w = source_rect(2);
            src->h = source_rect(3);
        }

        if(!dst_rect.is_empty()) {
            dst = new SDL_Rect();
            dst->x = dst_rect(0);
            dst->y = dst_rect(1);
            dst->w = dst_rect(2);
            dst->h = dst_rect(3);
        }

        // We want the render dispatch to preserve the ordering of calls. E.g.
        // If we have the following sequence
        //
        // render_dispatch dispatch_1 = renderer.copy();
        // renderer.target(another_texture);
        // dispatch_1.to(a_third_texture);
        //
        // we have to make sure that the dispatch copies its original contents
        // when the renderer was copied rather than the new target, making the
        // renderer relatively agnostic of its dispatchs. To do this, we save
        // and restore the current target of the renderer.
        texture* temp = r->target();
        r->target_window();
        int failure = SDL_RenderCopy(r->r, t->t, src, dst);

        // Don't want to try and set the target to NULL if there was no target!
        if(temp != NULL) r->target(t);

        delete src;
        delete dst;
        temp = 0;
        delete temp;

        if(failure) {
            throw sdl_exception("[render_dispatch::to] Error in copying from one texture to another.");
        }


    }
} /* zr  */ 
