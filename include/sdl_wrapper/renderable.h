#ifndef RENDERABLE_H
#define RENDERABLE_H


namespace zr {

    class renderer;

    /** Class abstraction for object that can be rendered by a sequence of
     * commands.
     *
     * Objects that inherit from this class must define the rendering behavior
     * for the given object. This abstraction enables the programmer to define
     * behavior that caters to the scenario and reuse objects which may be
     * rendererd similarly (e.g. a square or triangle).
     */
    class renderable {
        public:


            /** Constructor */
            renderable() {};


            /** Deconstructor */
            virtual ~renderable() {};

            
            /** Renders the object to the given renderer.
             *
             * This method must be implemented for any derived class, as it
             * gives the instructions for how the object is to be rendererd.
             *
             * @param r The renderer which should be used to curate render
             * commands
             */
            virtual void render(renderer* r, pos_i<int> pos) = 0;

    };

} /* zr  */ 

#endif /* RENDERABLE_H */   
