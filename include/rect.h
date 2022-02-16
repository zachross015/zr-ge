#ifndef RECT_H
#define RECT_H

#include <armadillo>

namespace zr {

    /** @todo Fill this out
     */
    template <class T>
    class rect {
        private:
            arma::Col<T> r;

        public:
                rect();
                virtual ~rect();

                const arma::Col<T>& get_rect();
                const T& get_x();
                const T& get_y();
                const T& get_width();
                const T& get_height();
                const arma::Col<T>& get_size();

                void set_rect(const arma::Col<T>& rect);
                void set_x(const T& x);
                void set_y(const T& y);
                void set_width(const T& width);
                void set_height(const T& height);
                void set_size(const arma::Col<T>& size);
    };

} /* zr  */ 

#endif /* RECT_H */   
