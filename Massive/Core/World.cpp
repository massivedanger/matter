//
//  World.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#define GLEW_STATIC
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
    _lastTime = _clock.getElapsedTime().asSeconds();
    
    _contextSettings.antialiasingLevel = 8;
    _window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Default, _contextSettings);
    
    _initialized = true;
    
    return _initialized;
}

void World::Destroy() {
    
}

void World::Start() {
    _running = true;
    _lastFPSTime = _clock.getElapsedTime().asSeconds();
    this->SetState(new State());
    
    while (_running && _window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        
        _window.clear(sf::Color::White);
        TickAndDraw();
        _window.display();
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
    if (_state) {
        _state->Draw();
    }
}

const float World::GetDT() {
    return _dt;
}

const float World::GetFPS() {
    return _lastFPS;
}

const String World::GetFPSString() {
    return M::floatToString(GetFPS());
}

float World::UpdateDT() {
    _currentTime = _clock.getElapsedTime().asSeconds();
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
