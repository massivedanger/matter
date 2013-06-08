//
//  State.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "State.h"
#include "World.h"
#include "../Entities/Actor.h"
#include "../Entities/Text.h"

State::State() {
    
}

void State::draw() {
    std::set<Screen *>::iterator screenIt = _screens.begin();
    while (screenIt != _screens.end()) {
        (*screenIt)->draw();
        screenIt++;
    }
}

void State::update(float dt) {
    std::set<Screen *>::iterator screenIt = _screens.begin();
    while (screenIt != _screens.end()) {
        (*screenIt)->update(dt);
        screenIt++;
    }
}

void State::addScreen(Screen *screen) {
    _screens.insert(screen);
}

void State::removeScreen(Screen *screen) {
    
}