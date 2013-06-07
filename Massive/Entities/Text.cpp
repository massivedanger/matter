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
    string = "";
    fontPath = MASSIVE_DEFAULT_FONT;
    
    font.loadFromFile(fontPath);
    
    _drawable.setString(string);
    _drawable.setCharacterSize(16);
    _drawable.setColor(sf::Color::Black);
    _drawable.setFont(font);
}

Text::~Text() {
    
}

void Text::Update(float dt) {
    
}

void Text::Draw() {
    theWorld.GetWindow().draw(_drawable);
}

void Text::SetPosition(int x, int y) {
    _drawable.setPosition(x, y);
}

void Text::MovePosition(int x, int y) {
    _drawable.move(x, x);
}

sf::Vector2f Text::GetPosition() {
    return _drawable.getPosition();
}

void Text::SetRotation(float rotation) {
    _drawable.setRotation(rotation);
}

void Text::Rotate(float rotation) {
    _drawable.rotate(rotation);
}

float Text::GetRotation() {
    return _drawable.getRotation();
}

void Text::SetScale(float scaleX, float scaleY) {
    _drawable.setScale(scaleX, scaleY);
}

void Text::Scale(float scaleX, float scaleY) {
    _drawable.scale(scaleX, scaleY);
}

sf::Vector2f Text::GetScale() {
    return _drawable.getScale();
}

void Text::SetOrigin(int x, int y) {
    _drawable.setOrigin(x, y);
}

sf::Vector2f Text::GetOrigin() {
    return _drawable.getOrigin();
}