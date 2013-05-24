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
    Screen *screen = new Screen();
    
    Actor *actor = new Actor();
    screen->AddEntity(actor, 0);
    Text *textActor = new Text("Hello, world.");
    screen->AddEntity(textActor, 0);
    
    this->AddScreen(screen);
}

void State::Draw() {
    std::set<Screen *>::iterator screenIt = _screens.begin();
    while (screenIt != _screens.end()) {
        (*screenIt)->Draw();
        screenIt++;
    }
}

void State::Update(float dt) {
    std::set<Screen *>::iterator screenIt = _screens.begin();
    while (screenIt != _screens.end()) {
        (*screenIt)->Update(dt);
        screenIt++;
    }
}

void State::AddScreen(Screen *screen) {
    _screens.insert(screen);
}

void State::RemoveScreen(Screen *screen) {
    
}