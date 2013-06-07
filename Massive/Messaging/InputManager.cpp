//
//  InputManager.cpp
//  Massive
//
//  Created by Evan Walsh on 7/6/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "InputManager.h"
#include "../Utilities/Common.h"
#include "../Utilities/Logger.h"
#include "Observer.h"

InputManager *InputManager::s_InputManager;

InputManager::InputManager() {
    
}

InputManager::~InputManager() {
    
}

InputManager &InputManager::getInstance() {
    if (s_InputManager == NULL) {
        s_InputManager = new InputManager();
    }
    
    return *s_InputManager;
}

void InputManager::keyPressed(sf::Event::KeyEvent event) {
    log.debug("Key pressed");
}

void InputManager::keyReleased(sf::Event::KeyEvent event) {
    log.debug("Key released");
}

void InputManager::mouseMoved(int x, int y) {
    log.debug("Mouse moved to x:" + M::intToString(x) + " y:" + M::intToString(y));
}

void InputManager::mouseWheelMoved(int delta, int x, int y) {
    log.debug("Mouse wheel moved by " + M::intToString(delta) + " notches");
}

void InputManager::mouseButtonPressed(sf::Mouse::Button button, int x, int y) {
    log.debug("Mouse button pressed at x:" + M::intToString(x) + " y:" + M::intToString(y));
}

void InputManager::mouseButtonReleased(sf::Mouse::Button button, int x, int y) {
    log.debug("Mouse button released at x:" + M::intToString(x) + " y:" + M::intToString(y));
}
