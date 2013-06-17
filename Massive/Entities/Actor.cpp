//
//  Actor.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Actor.h"
#include "../Core/World.h"

Actor::Actor() {
    _drawable = sf::CircleShape(10.0);
    _drawable.setFillColor( sf::Color(0, 0, 0) );
    theObserver.subscribe(this, "massive:key:pressed");
}

Actor::~Actor() {
    
}

void Actor::update(float dt) {
    _drawable.move(100 * dt, 100 * dt);
}

void Actor::draw() {
    theWorld.getWindow().draw(_drawable);
}

void Actor::receiveMessage(Message *message) {
    
}