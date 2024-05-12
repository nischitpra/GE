#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Window {
   public:
    Window();

    void draw();
};

#endif  // WINDOW_H