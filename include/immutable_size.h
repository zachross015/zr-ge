#ifndef IMMUTABLE_SIZE_H
#define IMMUTABLE_SIZE_H

namespace zr {

    /** Class template for a size construct that is immutable once initalized.
     * Only includes the getter access but may save on memory.
     */
    template <class T>
    class immutable_size {

        private:
            const T w, h;

        public:

            /** Constructor for the size getter.
             */
            immutable_size(T width, T height) : w(width), h(height) {};


            /** Deconstructor for the size getter.
             */
            virtual ~immutable_size() {};


            /** Gets the width this class is storing.
             *
             * @return The width of the container.
             */
            virtual const T& get_width() { return w; };


            /** Gets the height this class is storing.
             *
             * @return The height of the container.
             */
            virtual const T& get_height() { return h; };
    };

} /* zr  */ 

#endif /* IMMUTABLE_SIZE_H */
