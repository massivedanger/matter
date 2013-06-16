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

}

Actor::~Actor() {
    
}

void Actor::update(float dt) {
    
}

void Actor::draw() {
    sf::CircleShape circle(10.0);
    circle.setFillColor( sf::Color(0, 0, 0) );
    
    theWorld.getWindow().draw(circle);
}