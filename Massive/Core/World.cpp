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
    _contextSettings = new sf::ContextSettings();
    _window = new sf::RenderWindow();
    _state = new State();
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
World &World::getInstance() {
    if (s_World == NULL) {
        s_World = new World();
    }
    
    return *s_World;
}

/*!
 *  Initialize the World with configuration
 *  Call before World::Start()
 */
bool World::init(unsigned int windowWidth, unsigned int windowHeight, String windowTitle, bool fullscreen, bool antialias) {
    _lastTime = _clock.getElapsedTime().asSeconds();
    
    if (antialias) {
        _contextSettings->antialiasingLevel = 8;
    }
    
    _window->create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Default, *_contextSettings);
    
    camera = &theCamera;
    _initialized = true;
    
    return _initialized;
}

/*!
 *  Handle cleanup of all World-related data
 *  Called right before the game exits
 */
void World::destroy() {
    
}

/*!
 *  Start the game by displaying the window and polling for events
 *  Calls World::TickAndDraw();
 */
void World::start() {
    _running = true;
    _lastFPSTime = _clock.getElapsedTime().asSeconds();
    
    while (_running && _window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    _window->close();
                    break;
                case sf::Event::KeyPressed:
                    theInput.keyPressed(event.key);
                    break;
                case sf::Event::KeyReleased:
                    theInput.keyReleased(event.key);
                    break;
                case sf::Event::MouseMoved:
                    theInput.mouseMoved(event.mouseMove.x, event.mouseMove.y);
                    break;
                case sf::Event::MouseWheelMoved:
                    theInput.mouseWheelMoved(event.mouseWheel.delta, event.mouseWheel.x, event.mouseWheel.y);
                    break;
                case sf::Event::MouseButtonPressed:
                    theInput.mouseButtonPressed(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
                    break;
                case sf::Event::MouseButtonReleased:
                    theInput.mouseButtonReleased(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
                    break;
                case sf::Event::LostFocus:
                    lostFocus();
                    break;
                case sf::Event::GainedFocus:
                    gainedFocus();
                    break;
                case sf::Event::Resized:
                    resized();
                    break;
                default:
                    break;
            }
        }
        
        _window->clear(sf::Color::White);
        tickAndDraw();
        _window->display();
    }
}

/*!
 *  Stops the game and calls World::Destroy() to perform cleanup
 */
void World::stop() {
    _running = false;
    World::destroy();
}

//! Convenience function that calls World::Tick() and World::Draw()
void World::tickAndDraw() {
    tick();
    draw();
}

/*!
 *  Updates the Delta-Time (DT) for each frame (used for framerate indepence)
 *  Also, if a State is set, propogates new DT to the current state, which 
 *  sends it down the stack
 */
void World::tick() {
    float frameDT = updateDT();
    updateFPS();
    
    theObserver.sendAll();
    updateViewWithCamera(camera);
    
    if (_state) {
        _state->update(frameDT);
    }
}

/*!
 *  If a State is set, calls State::Draw() on that State
 */
void World::draw() {
    if (_state) {
        _state->draw();
    }
}

//! Convenience function for getting current FPS as a String
const String World::getFPSString() {
    return std::to_string(getFPS());
}

/*!
 *  Updates the stored Delta-Time float
 */
float World::updateDT() {
    _currentTime = _clock.getElapsedTime().asSeconds();
    _dt = _currentTime - _lastTime;
    _lastTime = _currentTime;
    
    return _dt;
}

/*!
 *  Updates the stored FPS float once per second
 */
void World::updateFPS() {
    if (_currentTime - _lastFPSTime > 1) {
        _lastFPS = _fps;
        _fps = 0;
        _lastFPSTime = _currentTime;
    }
    
    _fps++;
}

void World::updateViewWithCamera(Camera *camera) {
    _window->setView(camera->view);
}

void World::lostFocus() {
    theObserver.broadcast(new Message("massive:event:lost-focus", this));
}

void World::gainedFocus() {
    theObserver.broadcast(new Message("massive:event:gained-focus", this));
}

void World::resized() {
    theObserver.broadcast(new Message("massive:event:resized", this));
}

/*!
 *  Called when the World receives a message
 */
void World::receiveMessage(Message *message) {
    log.debug("World received message: " + message->name);
}
