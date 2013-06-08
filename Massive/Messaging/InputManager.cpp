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
    Message *mouseMessage = new Message("massive:key:pressed");
    theObserver.broadcast(mouseMessage);
}

void InputManager::keyReleased(sf::Event::KeyEvent event) {
    Message *mouseMessage = new Message("massive:key:released");
    theObserver.broadcast(mouseMessage);
}

void InputManager::mouseMoved(int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:moved");
    theObserver.broadcast(mouseMessage);
}

void InputManager::mouseWheelMoved(int delta, int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:wheel-moved");
    theObserver.broadcast(mouseMessage);
}

void InputManager::mouseButtonPressed(sf::Mouse::Button button, int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:pressed");
    theObserver.broadcast(mouseMessage);
}

void InputManager::mouseButtonReleased(sf::Mouse::Button button, int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:released");
    theObserver.broadcast(mouseMessage);
}
