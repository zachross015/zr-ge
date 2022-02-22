#ifndef RECT_H
#define RECT_H

#include "size.h"
#include "pos.h"
#include <armadillo>

namespace zr {

    /** Class template for a rectangle construct that is immutable once
     * initalized. Only includes getter access but may save on memory.
     */
    template <class T>
    class rect_i {
        private:
            const size_i<T> s;
            const pos_i<T> p;

        public:

            /** Default constructor for an immutable rectangle given a
             * position and size.              
             *
             * @param x The x coordinate of the rectangle
             * @param y The y coordinate of the rectangle
             * @param width  The width of the rectangle
             * @param height The height of the rectangle
             */
            rect_i(const T& x, const T& y, const T& width, const T& height) : p(x, y), s(width, height) {};


            /** Constructor for th rectangle using the underlying data types for
             * position and size.
             *
             * @param p The position of the rectangle
             * @param s The size/dimensions of the rectangle
             */
            rect_i(const pos_i<T>& p, const size_i<T>& s) : p(p), s(s) {};


            /** Constructor for rectangle given a column vector containing
             * four elements (x, y, width, height).
             *
             * @throw input_exception Throws this exception if the number of
             * rows in the column vector is not exactly four (how would you make
             * a higher dimensional rect dude??) or if there is more than one
             * column.
             *
             * @param r The column vector to initalize this rectangle class to.
             */
            rect_i(arma::Col<T> r) : p(r.rows(0, 1)), s(r.rows(2, 3)) { 
                if(r.n_rows != 4 || r.n_cols != 1) {
                    throw input_exception("[rect_i::rect_i] Invalid input dimensions for immutable rect. Must have exactly four elements (x, y, width, height).");
                }
            };


            /** Deconstructor for the rect getter.
             */
            virtual ~rect_i() {};


            /** Gets the x coordinate this class is storing.
             *
             * @return The x coordinate.
             */
            virtual T x() { return p.x(); };


            /** Gets the y coordinate this class is storing.
             *
             * @return The y coordinate.
             */
            virtual T y() { return p.y(); };


            /** Gets the underyling position class for the coordinate being
             * stored. 
             *
             * @return The underlying structure containing (x, y)'
             */
            virtual pos_i<T> pos() { return p; };


            /** Gets the width this class is storing.
             *
             * @return The width of the container.
             */
            virtual T width() { return s.width(); };


            /** Gets the height this class is storing.
             *
             * @return The height of the container.
             */
            virtual T height() { return s.height(); };


            /** Gets the size this class is storing.
             *
             * @return The size of the container.
             */
            virtual size_i<T> size() { return s; };


            /** Gets a column vector denoting the position and size of the
             * rectangle, with elements set as (x, y, width, height).
             *
             * @return Column vector containing the position and size of the
             * rectangle.
             */
            virtual arma::Col<T> rect() { return arma::join_cols(p.pos(), s.size()); }

    };


    template <class T>
    class rect_m {
        private:
            size_m<T> s;
            pos_m<T> p;

        public:

            /** Default constructor for an immutable sizing given a width and
             * height.
             *
             * @param width  The width of the size class
             * @param height The height of the size class
             */
            rect_m(const T& x, const T& y, const T& width, const T& height) : p(x, y), s(width, height) {};


            rect_m(const pos_m<T>& p, const size_m<T>& s) : p(p), s(s) {};


            /** Constructor for rect_i given a column vector containing
             * two elements.
             *
             * @throw input_exception Throws this exception if the number of
             * rows in the column vector is not exactly two (how would you make
             * a higher dimensional rect dude??)
             *
             * @param rect The column vector to initalize this rect class to.
             */
            rect_m(const arma::Col<T>& r) : p(r.rows(0, 1)), s(r.rows(2, 3)) { 
                if(r.n_rows != 4 || r.n_cols != 1) {
                    throw input_exception("[rect_i::rect_i] Invalid input dimensions for immutable rect. Must have exactly four elements (x, y, width, height).");
                }
            };


            /** Deconstructor for the rect getter.
             */
            virtual ~rect_m() {};


            /** Gets the x coordinate this class is storing.
             *
             * @return The x coordinate.
             */
            virtual T x() { return p.x(); };


            /** Sets the x coordinate this class is storing.
             *
             * @param val The x coordinate.
             */
            virtual void x(const T& val) { p.x(val); };


            /** Gets the y coordinate this class is storing.
             *
             * @return The y coordinate.
             */
            virtual T y() { return p.y(); };


            /** Sets the y coordinate this class is storing.
             *
             * @param val The y coordinate.
             */
            virtual void y(const T& val) { p.y(val); };


            /** Gets the pos this class is storing.
             *
             * @return The pos of the container.
             */
            virtual pos_m<T>& pos() { return p; };


            /** Sets the pos this class is storing.
             *
             * @param pos The pos to set this container to.
             */
            virtual void pos(const arma::Col<T>& ps) { p.pos(ps); };


            /** Gets the width this class is storing.
             *
             * @return The width of the container.
             */
            virtual T width() { return s.width(); };


            /** Sets the width this class is storing.
             *
             * @param width The width to set this container to.
             */
            virtual void width(const T& w) { s.width(w); };


            /** Gets the height this class is storing.
             *
             * @return The height of the container.
             */
            virtual T height() { return s.height(); };


            /** Sets the height this class is storing.
             *
             * @param height The height to set this container to.
             */
            virtual void height(const T& h) { s.height(h); };


            /** Gets the size this class is storing.
             *
             * @return The size of the container.
             */
            virtual size_m<T>& size() { return s; };


            /** Sets the size this class is storing.
             *
             * @param size The size to set this container to.
             */
            virtual void size(const arma::Col<T>& ps) { s.size(ps); };


            /** Gets a column vector denoting the position and size of the
             * rectangle, with elements set as (x, y, width, height).
             *
             * @return Column vector containing the position and size of the
             * rectangle.
             */
            virtual arma::Col<T> rect() { return arma::join_cols(p.pos(), s.size()); }


            /** Gets a column vector denoting the position and size of the
             * rectangle, with elements set as (x, y, width, height).
             *
             * @todo Add checks for this
             *
             * @param r Column vector containing the position and size of the
             * rectangle.
             */
            virtual void rect(arma::Col<T> r) { p.pos(r.rows(0, 1)); s.size(r.rows(2, 3)); };

    };

} /* zr  */ 


#endif /* RECT_H */
