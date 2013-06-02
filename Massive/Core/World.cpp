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

//! Constructor
World::World() {
    _running = false;
    _initialized = false;
}

//! Destructor
World::~World() {
    Listener::~Listener();
}

/*!
 *  Get the singleton instance of World for the game
 */
World &World::GetInstance() {
    if (s_World == NULL) {
        s_World = new World();
    }
    
    return *s_World;
}

/*!
 *  Initialize the World with configuration
 *  Call before World::Start()
 */
bool World::Init(unsigned int windowWidth, unsigned int windowHeight, String windowTitle, bool fullscreen, bool antialias) {
    _lastTime = _clock.getElapsedTime().asSeconds();
    
    _contextSettings.antialiasingLevel = 8;
    _window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Default, _contextSettings);
    
    _initialized = true;
    
    return _initialized;
}

/*!
 *  Handle cleanup of all World-related data
 *  Called right before the game exits
 */
void World::Destroy() {
    
}

/*!
 *  Start the game by displaying the window and polling for events
 *  Calls World::TickAndDraw();
 */
void World::Start() {
    _running = true;
    _lastFPSTime = _clock.getElapsedTime().asSeconds();
    
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

/*!
 *  Stops the game and calls World::Destroy() to perform cleanup
 */
void World::Stop() {
    _running = false;
    World::Destroy();
}

//! Convenience function that calls World::Tick() and World::Draw()
void World::TickAndDraw() {
    Tick();
    Draw();
}

/*!
 *  Updates the Delta-Time (DT) for each frame (used for framerate indepence)
 *  Also, if a State is set, propogates new DT to the current state, which 
 *  sends it down the stack
 */
void World::Tick() {
    float frameDT = UpdateDT();
    UpdateFPS();
    
    if (_state) {
        _state->Update(frameDT);
    }
}

/*!
 *  If a State is set, calls State::Draw() on that State
 */
void World::Draw() {
    if (_state) {
        _state->Draw();
    }
}

//! Convenience function for getting current FPS as a String
const String World::GetFPSString() {
    return M::floatToString(GetFPS());
}

/*!
 *  Updates the stored Delta-Time float
 */
float World::UpdateDT() {
    _currentTime = _clock.getElapsedTime().asSeconds();
    _dt = _currentTime - _lastTime;
    _lastTime = _currentTime;
    
    return _dt;
}

/*!
 *  Updates the stored FPS float once per second
 */
void World::UpdateFPS() {
    if (_currentTime - _lastFPSTime > 1) {
        _lastFPS = _fps;
        _fps = 0;
        _lastFPSTime = _currentTime;
    }
    
    _fps++;
}

/*!
 *  Called when the World receives a message
 */
void World::ReceiveMessage(Message *message) {
    
}
