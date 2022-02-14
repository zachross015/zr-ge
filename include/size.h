#ifndef SIZE_H
#define SIZE_H

namespace zr {

    /** Class template for a size construct that is mutable once initalized.
     * Includes getter and setter access.
     */
    template <class T>
    class size {

        private:
            T w, h;

        public:

            size(T width, T height) : w(width), h(height) {};

            virtual ~size() {};

            virtual void set_width(T width) { w = width; };

            virtual T get_width() { return w; };

            virtual void set_height(T height) { h = height; };

            virtual T get_height() { return h; };
    };

} /* zr  */ 

#endif /* SIZE_H */
