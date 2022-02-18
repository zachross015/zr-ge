#ifndef POS_H
#define POS_H

#include <armadillo>
#include "exceptions.h"

namespace zr {

    /** Class template for a pos construct that is immutable once initalized.
     * Only includes the getter access but may save on memory.
     */
    template <class T>
    class pos_i {

        private:
            const arma::Col<T> s;

        public:

            /** Default constructor for an immutable, 2D position vector given
             * an x and y coordinate.
             *
             * @param x The x coordinate of the position 
             * @param y The y coordinate of the position 
             */
            pos_i(const T& x, const T& y) : s({x, y}) {};


            /** Constructor for an immutable, 2D position vector given a column
             * vector containing two elements.
             *
             * @throw input_exception Throws this exception if the number of
             * rows in the column vector is not exactly two (how would you make
             * a higher dimensional pos dude??) or if there is any more than
             * one column.
             *
             * @param pos The column vector to initalize this pos class to.
             */
            pos_i(const arma::Col<T>& pos) : s(pos) { 
                if(pos.n_rows != 2 || pos.n_cols != 1) {
                    throw input_exception("[pos_i::pos_i] Invalid input dimensions for immutable pos. Must have exactly two elements for x and y in that order.");
                }
            };


            /** Deconstructor for the immutable position.
             */
            virtual ~pos_i() {};


            /** Gets the x coordinate this class is storing.
             *
             * @return The x coordinate.
             */
            virtual T x() { return s(0); };


            /** Gets the y coordinate this class is storing.
             *
             * @return The y coordinate.
             */
            virtual T y() { return s(1); };


            /** Gets the column vector for the coordinate being stored. 
             *
             * @return The column vector containing (x, y)'
             */
            virtual arma::Col<T> pos() { return s; };
    };


    /** Class template for a pos construct that is mutable once initalized.
     * Includes getter and setter access.
     */
    template <class T>
    class pos_m {

        private:
            arma::Col<T> s;

        public:

            /** Default constructor for an mutable, 2D position vector given
             * an x and y coordinate.
             *
             * @param x The x coordinate of the position 
             * @param y The y coordinate of the position 
             */
            pos_m(const T& x, const T& y) : s({x, y}) {};


            /** Constructor for an mutable, 2D position vector given a column
             * vector containing two elements.
             *
             * @throw input_exception Throws this exception if the number of
             * rows in the column vector is not exactly two (how would you make
             * a higher dimensional pos dude??) or if there is any more than
             * one column.
             *
             * @param pos The column vector to initalize this pos class to.
             */
            pos_m(const arma::Col<T>& pos) : s(pos) { 
                if(pos.n_rows != 2 || pos.n_cols != 1) {
                    throw input_exception("[pos_m::pos_m] Invalid input dimensions for mutable pos. Must have exactly two elements for x and y (in that order).");
                }
            };


            /** Deconstructor for the pos class.
             */
            virtual ~pos_m() {};
            

            /** Sets the x coordinate this class is storing.
             *
             * @param val The x coordinate.
             */
            virtual void x(const T& val) { s(0) = val; };


            /** Gets the x coordinate this class is storing.
             *
             * @return The x coordinate.
             */
            virtual T x() { return s(0); };


            /** Sets the y coordinate this class is storing.
             *
             * @param val The y coordinate.
             */
            virtual void y(const T& val) { s(1) = val; };


            /** Gets the y coordinate this class is storing.
             *
             * @return The y coordinate.
             */
            virtual T y() { return s(1); };


            /** Sets the column vector for the coordinate being stored. 
             *
             * @todo Add exceptions for incorrect dimension size.
             *
             * @param pos The column vector containing (x, y)' to set this
             * structure to.
             */
            virtual void pos(const arma::Col<T>& pos) { s = pos; };


            /** Gets the column vector for the coordinate being stored. 
             *
             * @return The column vector containing (x, y)'
             */
            virtual arma::Col<T> pos() { return s; };
    };

} /* zr  */ 

#endif /* POS_H */
