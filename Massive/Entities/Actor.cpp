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
    _drawable = sf::CircleShape(100.0);
    _drawable.setFillColor( sf::Color(0, 0, 0) );
}

Actor::~Actor() {
    
}

void Actor::update(float dt) {
    
}

void Actor::draw() {
    theWorld.getWindow().draw(_drawable);
}

void Actor::setPosition(int x, int y) {
    _drawable.setPosition(x, y);
}

void Actor::movePosition(int x, int y) {
    _drawable.move(x, x);
}

sf::Vector2f Actor::getPosition() {
    return _drawable.getPosition();
}

void Actor::setRotation(float rotation) {
    _drawable.setRotation(rotation);
}

void Actor::rotate(float rotation) {
    _drawable.rotate(rotation);
}

float Actor::getRotation() {
    return _drawable.getRotation();
}

void Actor::setScale(float scaleX, float scaleY) {
    _drawable.setScale(scaleX, scaleY);
}

void Actor::scale(float scaleX, float scaleY) {
    _drawable.scale(scaleX, scaleY);
}

sf::Vector2f Actor::getScale() {
    return _drawable.getScale();
}

void Actor::setOrigin(int x, int y) {
    _drawable.setOrigin(x, y);
}

sf::Vector2f Actor::getOrigin() {
    return _drawable.getOrigin();
}

void Actor::receiveMessage(Message *message) {
    log.debug("Actor received a message: " + message->name);
}