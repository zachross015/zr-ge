#ifndef SDL_EXCEPTION_H
#define SDL_EXCEPTION_H

#include <exception>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

namespace zr {

    // TODO: It might be more beneficial down the line to include some macros
    // which help to facilitate the throwing and sending of exceptions. Right
    // now it takes ~3 lines of code per exception case, not including the text
    // involved. It would be preferable if we had the following:
    // 1) IF statement/checking macros
    // 2) Macros which auto populate line no. and function/class names.

    /** Class of exceptions which deals with errors that occur within the SDL
     * codebase. It primarily does so by reiterating whatever error message is
     * passed to the class, along with the message passed along by SDL_GetError.
     * Part of the big reason for creating such a wrapper was to include
     * stronger typing and exception handling as is provided by more modern c++,
     * which is what this struct helps to facilitate.
     */
    struct sdl_exception: public std::exception {
        std::string message;
        const char* what() const throw() { std::cout << " SDL EXCEPTION " << message << std::endl; return SDL_GetError(); }
        sdl_exception(std::string m) : message(m) {};
    };


    /** Class of exceptions dealing with input errors that occur in the
     * codebase. So far, these primarily deal with errors in matrix
     * dimensionality; however, this can be extended much further if need be.
     */
    struct input_exception: public std::exception {
        std::string message;
        const char* what() const throw() { std::cout << " INPUT EXCEPTION " << message << std::endl; return ""; }
        input_exception(std::string m) : message(m) {};
    };


    /** Class of exceptions dealing with errors that occur within the SDL_image
     * codebase. It restates the messages passed by SDL_image with some added
     * information by the compiler.
     */
    struct sdl_img_exception: public std::exception {
        std::string message;
        const char* what() const throw() { std::cout << " SDL IMAGE EXCEPTION " << message << std::endl; return IMG_GetError(); }
        sdl_img_exception(std::string m) : message(m) {};
    };
}


#endif /* SDL_EXCEPTION_H */
