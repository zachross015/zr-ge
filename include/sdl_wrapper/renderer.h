#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <armadillo>
#include "window.h"
#include "blend_mode.h"
#include "color.h"

namespace zr {

    class texture;
    class render_dispatch;

    /** Enumeration of the different renderer states permitted by SDL.
     */
    enum renderer_state {
        software = SDL_RENDERER_SOFTWARE,
        accelerated = SDL_RENDERER_ACCELERATED,
        present_vsync = SDL_RENDERER_PRESENTVSYNC,
        target_texture = SDL_RENDERER_TARGETTEXTURE
    };

    /** Retrieves the list of all possible render states for enumeration
     * purposes.
     *
     * @return std::vector<render_state> consisting of all possible render
     * states.
     */
    std::vector<renderer_state> all_renderer_states();

    /** Ostream operator overload for the render_state enumerator.
     *
     * @param  out The ostream
     * @param  ws  The render state to be printed out
     * @return     The outputted render state.
     */
    std::ostream& operator<<(std::ostream& out, const renderer_state& ws);


    /** Class construct for drawing things.
     *
     * @todo Consider removing the public constructor in favor of a constructor
     * inside 'window' since the renderer has to be connected to the window.
     * @todo Consider separating into two classes for window rendering and
     * texture rendering. Would there be any benefit to this either than taking
     * out the `copy` function?
     */
    class renderer {
        private:

            friend class texture;
            friend class render_dispatch;

            // The underlying renderer we are drawing to.
            SDL_Renderer* r;

            // The target this renderer is drawing to. Currently NULL if we are
            // drawing to the window instead. See the todo in the defintion.
            texture* tar;

        public:


            /** Support for the SDL renderer init with stronger typing. 
             *
             * @param w     The window to initialize the renderer from
             * @param rs    The configuration of renderer states for this
             *              renderer (default = {})
             * @param index The index of the rendering driver or -1 for the
             *              first one supporting the requested flags. (default =
             *              -1)
             *
             * @throw sdl_exception Error when creating the renderer. 
             */
            renderer(const window& w, 
                     const std::vector<renderer_state>& rs = {},
                     int index = -1);


            /** Deconstructs the renderer.
             */
            virtual ~renderer();


            /** Get the blend mode used for drawing operations.
             * 
             * @throw sdl_exception Error when retrieving the blend mode.
             *
             * @return Associate blend mode.
             */
            blend_mode blend();


            /** Set the blend mode used for drawing operations.
             * 
             * @throw sdl_exception Error when retrieving the blend mode.
             *
             * @param bm Associate blend mode.
             */
            void blend(const blend_mode& bm);


            /** Gets the the current color that this renderer is drawing in.
             *
             * @return The color this renderer is using to draw.
             */
            color draw_color();

            /** Tells the renderer which color to switch to.
             *
             * The renderer can be imagined as someone drawing in a
             * coloring book with a certain color of crayon. Until told that
             * they should switch to a different color, they will continue to
             * color absolutely EVERYTHING in that color. That is why we have to
             * tell the renderer to switch whenever we want color changes.
             *
             * @param c The color that the renderer should switch to.
             */
            void draw_color(const color& c);


            /** Return the size of the rendering window.
             *
             * @return Column vector containing the width (index 0) and height
             * (index 1).
             */
            arma::Col<int> output_size() ;


            /** Resets all pixels in the render to the current draw color. See
             * `draw_color` for more information on how
             * to view or change what this color is.
             */
            void clear();


            /** Draws the specified series of lines to this renderer. 
             *
             * The lines are sequentially read from the given matrix, meaning
             * there needs to be 2 columns per row s.t. the first column (index
             * 0) is the x coordinate and the second column (index 1) is the y
             * coordinate of each point in the sequence of lines.
             *
             * @throw input_exception This is thrown if there are too few rows
             * (<2) or the number of columns isn't exactly 2.  
             * @throw sdl_exception This occurs if there is an error with SDL
             * drawing the lines.
             *
             * @param lines Matrix consisting of the sequential ordering for
             * which the lines should be formed. E.g. if there were four
             * entries, we should have that the lines are formed by (0) - (1),
             * (1) - (2), and finally (2) - (3). The columns should be the xy
             * coordinates while the rows should be the entries.
             *
             */
            void draw_lines(const arma::Mat<float>& lines);

            
            /** Draws the specified series of points to this renderer. 
             *
             * The points are sequentially read from the given matrix, meaning
             * there needs to be 2 columns per row s.t. the first column (index
             * 0) is the x coordinate and the second column (index 1) is the y
             * coordinate of each point.
             *
             * @throw input_exception This is thrown if there are too few rows
             * (<1) or the number of columns isn't exactly 2.  
             * @throw sdl_exception This occurs if there is an error with SDL
             * drawing the points.
             *
             * @param points Matrix consisting of the sequential ordering for
             * which the points should be drawn.
             */
            void draw_points(const arma::Mat<float>& points);


            /** Draws the specified series of rectangles to this renderer. 
             *
             * The rectangles are sequentially read from the given matrix,
             * meaning there needs to be 4 columns per row s.t. the first column
             * (index 0) is the x coordinate, the second column (index 1) is
             * the y coordinate, the third column (index 2) is the width, and
             * the fourth column (index 3) is the height.
             *
             * @throw input_exception This is thrown if there are too few rows
             * (<1) or the number of columns isn't exactly 4.  
             * @throw sdl_exception This occurs if there is an error with SDL
             * drawing the rectangles.
             *
             * @param rects Matrix consisting of the sequential ordering for
             * which the rectangles should be drawn.              
             */
            void draw_rects(const arma::Mat<float>& rects);

  
            /** Draws the specified series of rectangles to this renderer,
             * filling them in with this renderer's draw color.
             *
             * The rectangles are sequentially read from the given matrix,
             * meaning there needs to be 4 columns per row s.t. the first column
             * (index 0) is the x coordinate, the second column (index 1) is
             * the y coordinate, the third column (index 2) is the width, and
             * the fourth column (index 3) is the height.
             *
             * @throw input_exception This is thrown if there are too few rows
             * (<1) or the number of columns isn't exactly 4.  
             * @throw sdl_exception This occurs if there is an error with SDL
             * drawing the rectangles.
             *
             * @param rects Matrix consisting of the sequential ordering for
             * which the rectangles should be drawn.              
             */
            void fill_rects(const arma::Mat<float>& rects);


            /** Sends the information in this renderer to the window it's
             * connected to.
             */
            void present();


            /** Get the clip rectangle for the current target.
             *
             * @return Column vector filled with the current clipping area (x,
             * y, w, h) or an empy rectangle if clipping is disabled.
             *
             * @todo This may result in an error, especially if SDL_Rect* rect
             * turns out to be NULL if clipping is disabled.
             */
            arma::Col<int> clip_rect();


            /** Set the clip rectangle for rendering on the specified target.
             *
             * @throw sdl_exception An exception thrown if there is an error
             * when applying the clipping.
             *
             * @param cr The clipping area matrix with entries as (x, y, w, h).
             * Note that this is relative to the viewport.
             */
            void clip_rect(const arma::Col<int>& cr);


            /** Get whether integer scales are forced for resolution-independent
             * rendering.
             *
             * @return true if they are forced, false otherwise.
             */
            bool integer_scales_are_forced();


            /** Set whether integer scales are forced for resolution-independent
             * rendering.
             *
             * @throw sdl_exception Error thrown if SDL has an error with
             * setting this value.
             *
             * @param tf True if they should be forced, false otherwise.
             */
            void force_integer_scales(bool tf);


            /** Get device independent resolution for rendering.
             *
             * @remark May return 0 for both if renderer has never had its
             * logical size set by SDL_RenderSetLogicalSize and never had a
             * render target set.
             * 
             * @return 2D vector containing width (0) and height (1) for the
             * independent resolution size.
             */
            arma::Col<int> logical_size();


            /** Set device independent resolution for rendering.
             *
             * @param ls 2D vector containing width (0) and height (1) for the
             * independent resolution size.
             */
            void logical_size(const arma::Col<int>& ls);


            /** Get the drawing scale for the current target.
             *
             * @return 2D Drawing scale for the target (x, y)
             */
            arma::Col<float> scale();


            /** Set the drawing scale for the current target.
             *
             * @throw sdl_exception Error that occurs if SDL has a problem.
             *
             * @param s 2D Drawing scale for the target (x, y)
             */
            void scale(const arma::Col<float>& s);


            /** Get the drawing area for the current target.
             *
             * @return 2D Drawing area for the target (x, y)
             */
            arma::Col<int> viewport();


            /** Set the drawing area for the current target.
             *
             * @throw sdl_exception Error that occurs if SDL has a problem.
             *
             * @param s 2D Drawing area for the target (x, y)
             */
            void viewport(const arma::Col<int>& vp);


            /** Get whether clipping is enabled on this renderer.
             *
             * @return true if clipping is enabled, false otherwise.
             */
            bool is_clipping_enabled();


            // TODO: Implement this in some form or another.
            void read_pixels(const arma::Col<int>& vp, 
                             const pixel_format& format, 
                             void* pixels, 
                             int pitch) {}
            

            /** Determine whether this renderer supports the use of render
             * targets.
             *
             * @return true if this supports render targets, false otherwise.
             */
            bool supports_targets();


            /** Set the target of this renderer. 
             *
             * Once the target is set, all further drawing operations from this
             * renderer will be performed on the passed target. 
             *
             * @todo Consider modifying this code further down the line to
             * except references instead of needing pointer. I don't have time
             * to put this in now, but that would save a lot of headaches tbh.
             *
             * @throw input_exception An exception that will occur if the user
             * attempts to send an unitialized texture to this renderer.
             * @throw input_exception An exception that will occur if the wrong
             * type of texture access is used with this method. Textures that
             * are to be used as targets must have target access.
             *
             * @param t A pointer to the texture which this renderer should
             * target for drawing operations.
             */
            void target(texture* t);


            /** Get the texture this renderer is currently targeting.
             *
             * Delivers the requested target to the programmer. Will return NULL
             * if the renderer is targetting the window instead of a texture.
             *
             * @return The texture this renderer is targetting or NULL if the the
             * window is targetted.
             */
            texture* target();


            /** Sets the target of this renderer to the window it was
             * initialized with.
             *
             * Renderers can't change windows after initialization (per SDL
             * standard) so when this function is called, the renderer is
             * defaulted back to its original rendering medium. 
             */
            void target_window();


            /** Creates a render dispatched for determining where this renderer
             * should copy its contents to. 
             *
             * When this method is called, the renderer begins the process of
             * copying its current target into a further specified target. This
             * second target is specified in the render_dispatch and can either
             * be another texture or just a window.
             *
             * @param source_rect The source rectangle of the texture to be
             * copied into a target. Note that if this source rectangle's size
             * doesn't match that of the destinations (in render_dispatch), then 
             * the source texture will be stretched based on its
             * texture_scaling_method.
             *
             * @return A render_dispatch instance containing the information
             * needed to copy the current target to a specified target.
             */
            render_dispatch copy(const arma::Col<int>& source_rect = {});

            // TODO: The following methods need to be implemented still for this
            // wrapper.
            // - SDL_GetRendererInfo
    };

} /* zr  */ 

#endif /* RENDERER_H */ 
