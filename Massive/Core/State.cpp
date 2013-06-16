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

State::~State() {
    
}

void State::draw() {
    for (auto screen : _screens) {
        screen->draw();
    }
}

void State::update(float dt) {
    for (auto screen : _screens) {
        screen->update(dt);
    }
}

void State::addScreen(Screen *screen) {
    _screens.insert(screen);
}

void State::removeScreen(Screen *screen) {
    
}