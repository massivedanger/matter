//
//  Actor.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Actor.h"

Actor::Actor() {
    
}

void Actor::Update(float dt) {
    printf("The actor says the delta is %f\n", dt);
}

void Actor::Draw() {
    printf("The actor is being drawn");
}