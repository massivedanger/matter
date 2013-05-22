//
//  World.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#define GLEW_STATIC
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

bool World::Init(unsigned int windowWidth, unsigned int windowHeight, String windowTitle, bool fullscreen, bool antialias) {
    if (!glfwInit())
        return false;
    
    if (antialias) {
        glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
        _antialiased = true;
    }
    
    int screenMode = fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW;
    if (!glfwOpenWindow(windowWidth, windowHeight, 8, 8, 8, 0, 24, 0, screenMode))
        return false;
    
    
    // Center window
    GLFWvidmode vidMode;
    glfwGetDesktopMode(&vidMode);
    int screenHeight = vidMode.Height;
    int screenWidth = vidMode.Width;
    
    glfwSetWindowPos((screenWidth / 2) - (windowWidth / 2), (screenHeight / 2) - (windowHeight / 2));
    glfwSetWindowTitle(windowTitle.c_str());
    glfwSwapInterval(0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    
    _lastTime = glfwGetTime();
    _initialized = true;
    
    return _initialized;
}

void World::Destroy() {
    
}

void World::Start() {
    _running = true;
    _lastFPSTime = glfwGetTime();
    this->SetState(new State());
    
    while (_running && glfwGetWindowParam(GLFW_OPENED)) {
        TickAndDraw();
    }
}

void World::Stop() {
    _running = false;
}

void World::TickAndDraw() {
    Tick();
    Draw();
}

void World::Tick() {
    float frameDT = UpdateDT();
    UpdateFPS();
    
    if (_state) {
        _state->Update(frameDT);
    }
}

void World::Draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (_state) {
        _state->Draw();
    }
    
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
