Loading and Rendering Resources {#loading-and-rendering-resources}
==================================================================

### How should I specify where the resource is located?

You've probably run into this pesky bug at some point:
```
terminate called after throwing an instance of <error>
  what():  Couldn't open <resource>
Aborted (core dumped)
```
Worry not! We have the solution. When you are writing your program, it's
important to make sure you specify the correct path for your resources. With
absolute paths, this isn't an issue since your program knows exactly where to
find a specified resource. With relative paths however, it's important that you
understand how the location you call the program from alters the program.

As an example, consider the directory structure:
```
project/
    src/
        main.cpp
    include/
    resources/
    fonts/
        main.ttf
    executable
```
where `main.cpp` loads the font using a relative path and the code
`load_font("fonts/main.ttf")`. Under these conditions, the code will only
perform as expected if it is called from within the project directory using
`./executable`. On the other hand, using an absolute path
`load_font("<path-to-fonts>/fonts/main.ttf")` will work regardless of where
the program is being called.


\todo Make the resource loading more intuitive. Right now we have to specify the
full resource path from the root directory and it would be much more preferable
if we could basically isolate the examples so that they are independent of the
overall framework structure.

\todo Research more on entt and create a more global storage structure that
interfaces very intuitively with the renderer.

Fonts and Text {#fonts-and-text}
--------------------------------

The general process for loading in fonts and rendering text comes in a few steps:

1. load the font resource,
2. render the font to a texture,
3. and render the texture to the screen.

We start by including the game engine library, construct a window, and construct
a renderer, since these steps are necessary for any of the following code. This
is done with:
```cpp
#include <game-engine.hpp>
...
ge::window wind;
ge::renderer ren = wind.make_renderer();
```
Once that is loaded in, we can load the font resource by constructing a
\ref cen::font "font" object:
```cpp
ge::font fnt(<filname>, <font-size>);
```
then rendering the font to a texture:
```cpp
auto txt = ren.make_texture(fnt.render_blended(<text-string>, <color>));
```
Finally, during a drawing loop, the text can be rendered and presented using:
```cpp
ren.render(txt, <point>);
ren.present();
```
A minimal example of this is given below:

\include examples/minimal-font-rendering/main.cpp
