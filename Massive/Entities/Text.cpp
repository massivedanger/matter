//
//  Text.cpp
//  Massive
//
//  Created by Evan Walsh on 8/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Text.h"
#include "../Core/World.h"

Text::Text() {
    _string = "Text";
    _fontPath = MASSIVE_DEFAULT_FONT;
    
    font.loadFromFile(_fontPath);
    
    _drawable.setString(_string);
    _drawable.setCharacterSize(16);
    _drawable.setColor(sf::Color::Black);
    _drawable.setFont(font);
}

Text::~Text() {
    
}

void Text::update(float dt) {
    
}

void Text::draw() {
    theWorld.getWindow().draw(_drawable);
}

void Text::setString(String newString) {
    _drawable.setString(newString);
}

String Text::getString() {
    return _drawable.getString();
}

void Text::setPosition(int x, int y) {
    _drawable.setPosition(x, y);
}

void Text::movePosition(int x, int y) {
    _drawable.move(x, x);
}

sf::Vector2f Text::getPosition() {
    return _drawable.getPosition();
}

void Text::setRotation(float rotation) {
    _drawable.setRotation(rotation);
}

void Text::rotate(float rotation) {
    _drawable.rotate(rotation);
}

float Text::getRotation() {
    return _drawable.getRotation();
}

void Text::setScale(float scaleX, float scaleY) {
    _drawable.setScale(scaleX, scaleY);
}

void Text::scale(float scaleX, float scaleY) {
    _drawable.scale(scaleX, scaleY);
}

sf::Vector2f Text::getScale() {
    return _drawable.getScale();
}

void Text::setOrigin(int x, int y) {
    _drawable.setOrigin(x, y);
}

sf::Vector2f Text::getOrigin() {
    return _drawable.getOrigin();
}