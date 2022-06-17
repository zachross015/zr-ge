#ifndef COMPONENTS_H
#define COMPONENTS_H

/// Component for dictating entity position
struct position {
    float x, y;
};


/// Component for dictating entity velocity
struct velocity {
    float dx, dy;
};


/// Enumeration for the different sides a pong paddle can be on
enum paddle_side {
    left, right
};


/// Component for dictating which side the pong paddle is on
struct paddle {
    paddle_side side;
    int score = 0;
};


/// Ball component, pretty self explanatory.
struct ball {
    int lifetime = 0;
};

#endif
