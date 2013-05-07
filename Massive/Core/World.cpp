//
//  World.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include <GL/glfw.h>
#include "World.h"

World *World::s_World;

World::World() {
    _running = false;
    _initialized = false;
}

World::~World() {
    Listener::~Listener();
}

World &World::GetInstance() {
    if (s_World == NULL) {
        s_World = new World();
    }
    
    return *s_World;
}

bool World::Init(unsigned int windowWidth, unsigned int windowHeight, String windowTitle, bool fullscreen) {
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

void World::Destroy() {
    
}

void World::Start() {
    _running = true;
    _lastFPSTime = glfwGetTime();
    
    while (_running && glfwGetWindowParam(GLFW_OPENED)) {
        TickAndRender();
    }
}

void World::Stop() {
    _running = false;
}

void World::TickAndRender() {
    Tick();
    Render();
}

void World::Tick() {
    float frameDT = UpdateDT();
    UpdateFPS();
    
    if (_state) {
        _state->Update(frameDT);
    }
    
    printf("Last FPS: %f\n", _lastFPS);
}

void World::Render() {
    // TODO: actually...draw...something?
    
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // swap back and front buffers
    glfwSwapBuffers();
}

const float World::GetDT() {
    return _dt;
}

const float World::GetFPS() {
    return _lastFPS;
}

float World::UpdateDT() {
    _currentTime = glfwGetTime();
    _dt = _currentTime - _lastTime;
    _lastTime = _currentTime;
    
    return _dt;
}

void World::UpdateFPS() {
    if (_currentTime - _lastFPSTime > 1) {
        _lastFPS = _fps;
        _fps = 0;
        _lastFPSTime = _currentTime;
    }
    
    _fps++;
}

void World::ReceiveMessage(Message *message) {
    
}
