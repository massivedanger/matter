//
//  main.cpp
//  thelasterror
//
//  Created by Evan Walsh on 1/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Massive.h"

#include <GL/glfw.h>

int main(int argc, const char * argv[])
{
    
    const int   windowWidth = 960,
    windowHeight = 600;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    /* Create a windowed mode window and its OpenGL context */
    if (!glfwOpenWindow(windowWidth, windowHeight, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
        return -1;
    
    glfwSetWindowTitle("The Last Error");
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = ((float)windowHeight) / windowWidth;
    glFrustum(.5, -.5, -.5 * aspectRatio, .5 * aspectRatio, 1, 50);
    glMatrixMode(GL_MODELVIEW);
    glfwSwapInterval(0); // Turn off vsync
    
    /* Loop until the user closes the window */
    double lastTime = glfwGetTime();
    while (glfwGetWindowParam(GLFW_OPENED))
    {
        // Handle delta for updating
        double currentTime = glfwGetTime(),
        delta = (currentTime - lastTime);
        lastTime = currentTime;
        
        // clear the buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // swap back and front buffers
        glfwSwapBuffers();
    }
    
    return 0;
}
