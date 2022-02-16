#ifndef SIZE_H
#define SIZE_H

#include <armadillo>
#include "exceptions.h"

namespace zr {

    /** Class template for a size construct that is mutable once initalized.
     * Includes getter and setter access.
     */
    template <class T>
    class size {

        private:
            arma::Col<T> s;

        public:

            /** Default constructor for an mutable sizing given a width and
             * height.
             *
             * @param width  The width of the size class
             * @param height The height of the size class
             */
            size(T width, T height) : s({width, height}) {};


            /** Constructor for mutable_size given a column vector containing
             * two elements.
             *
             * @throw input_exception Throws this exception if the number of
             * rows in the column vector is not exactly two (how would you make
             * a higher dimensional size dude??)
             *
             * @param size The column vector to initalize this size class to.
             */
            size(arma::Col<T> size) : s(size) { 
                if(size.n_rows != 2) {
                    throw input_exception("[mutable_size::mutable_size] Invalid input dimensions for mutable size. Must have exactly two elements for width and height in that order.");
                }
            };


            /** Deconstructor for the size class.
             */
            virtual ~size() {};
            

            /** Sets the width this class is storing.
             *
             * @param width The width to set this container to.
             */
            virtual void set_width(const T& width) { s(0) = width; };


            /** Gets the width this class is storing.
             *
             * @return The width of the container.
             */
            virtual const T& get_width() { return s(0); };


            /** Sets the height this class is storing.
             *
             * @param height The height to set this container to.
             */
            virtual void set_height(const T& height) { s(1) = height; };


            /** Gets the height this class is storing.
             *
             * @return The height of the container.
             */
            virtual const T& get_height() { return s(1); };


            /** Sets the size this class is storing.
             *
             * @param size The size to set this container to.
             */
            virtual void set_size(const arma::Col<T>& size) { s = size; };


            /** Gets the size this class is storing.
             *
             * @return The size of the container.
             */
            virtual const arma::Col<T>& get_size() { return s; };
    };

} /* zr  */ 

#endif /* SIZE_H */
