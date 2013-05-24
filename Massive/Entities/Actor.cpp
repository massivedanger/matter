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
void Actor::Update(float dt) {
    
}

void Actor::Draw() {
    sf::CircleShape circle(theWorld.GetFPS());
    circle.setFillColor( sf::Color(0, 0, 0) );
    
    theWorld.GetWindow().draw(circle);
}

Actor::~Actor() {
    
}