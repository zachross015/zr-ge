#ifndef IMMUTABLE_SIZE_H
#define IMMUTABLE_SIZE_H

#include <armadillo>
#include "exceptions.h"

namespace zr {

    /** Class template for a size construct that is immutable once initalized.
     * Only includes the getter access but may save on memory.
     */
    template <class T>
    class immutable_size {

        private:
            const arma::Col<T> s;

        public:

            /** Default constructor for an immutable sizing given a width and
             * height.
             *
             * @param width  The width of the size class
             * @param height The height of the size class
             */
            immutable_size(T width, T height) : s({width, height}) {};


            /** Constructor for immutable_size given a column vector containing
             * two elements.
             *
             * @throw input_exception Throws this exception if the number of
             * rows in the column vector is not exactly two (how would you make
             * a higher dimensional size dude??)
             *
             * @param size The column vector to initalize this size class to.
             */
            immutable_size(arma::Col<T> size) : s(size) { 
                if(size.n_rows != 2) {
                    throw input_exception("[immutable_size::imutable_size] Invalid input dimensions for immutable size. Must have exactly two elements for width and height in that order.");
                }
            };


            /** Deconstructor for the size getter.
             */
            virtual ~immutable_size() {};


            /** Gets the width this class is storing.
             *
             * @return The width of the container.
             */
            virtual const T& width() { return s(0); };


            /** Gets the height this class is storing.
             *
             * @return The height of the container.
             */
            virtual const T& height() { return s(1); };


            /** Gets the size this class is storing.
             *
             * @return The size of the container.
             */
            virtual const arma::Col<T>& size() { return s; };
    };

} /* zr  */ 

#endif /* IMMUTABLE_SIZE_H */
