//
//  World.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "World.h"
#include <GL/glfw.h>

World *World::s_World;

World::World()
{
    _running = false;
    _initialized = false;
}

World &World::GetInstance() {
    if (s_World == NULL) {
        s_World = new World();
    }
    
    return *s_World;
}

bool World::Init(unsigned int windowWidth, unsigned int windowHeight, String windowTitle, bool fullscreen)
{
    /* Initialize the library */
    if (!glfwInit())
        return false;
    
    /* Create a windowed mode window and its OpenGL context */
    if (!glfwOpenWindow(windowWidth, windowHeight, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
        return false;
    
    glfwSetWindowTitle(windowTitle.c_str());
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = ((float)windowHeight) / windowWidth;
    glFrustum(.5, -.5, -.5 * aspectRatio, .5 * aspectRatio, 1, 50);
    glMatrixMode(GL_MODELVIEW);
    glfwSwapInterval(0); // Turn off vsync
    
    _lastTime = glfwGetTime();
    
    _initialized = true;
    
    return _initialized;
}

void World::Destroy()
{
    
}

void World::Start()
{
    _running = true;
    while (glfwGetWindowParam(GLFW_OPENED))
    {
        TickAndRender();
        
        // clear the buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // swap back and front buffers
        glfwSwapBuffers();
    }
}

void World::Stop()
{
    
}

void World::TickAndRender()
{
    Tick();
    Render();
}

void World::Tick()
{
    float frameDT = CalculateNewDT();
    if (_state) {
        _state->Update(frameDT);
    }
}

void World::Render()
{
    
}

const float World::GetDelta()
{
    return _dt;
}

float World::CalculateNewDT()
{
    _currentTime = glfwGetTime();
    _dt = _currentTime - _lastTime;
    _lastTime = _currentTime;
    
    return _dt;
}
