#ifndef GAME_INITIALIZATION_H
#define GAME_INITIALIZATION_H


#include <centurion.hpp>
#include <entt/entt.hpp>
#include <effolkronium/random.hpp>


namespace ge {

    using namespace cen;
    using namespace entt;
    using rand = effolkronium::random_static;

    // Initialize sdl libraries
    const sdl _sdl;
    const img _img;
    const ttf _ttf;
    const mix _mix;

};


#endif
