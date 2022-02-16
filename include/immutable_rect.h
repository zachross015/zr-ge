#ifndef IMMUTABLE_RECT_H
#define IMMUTABLE_RECT_H

#include <armadillo>

namespace zr {


    /** @todo Fill this out
     */
    template <class T>
    class immutable_rect {
        private:
            arma::Col<T> r;

        protected:
            SDL_Rect to_sdl_rect();

        public:
                immutable_rect();
                virtual ~immutable_rect();

                const arma::Col<T>& get_rect();
                const T& get_x();
                const T& get_y();
                const T& get_width();
                const T& get_height();
                const arma::Col<T>& get_size();
    };

} /* zr  */ 

#endif /* IMMUTABLE_RECT_H */   
