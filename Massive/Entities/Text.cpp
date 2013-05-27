//
//  Text.cpp
//  Massive
//
//  Created by Evan Walsh on 8/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Text.h"
#include "../Core/World.h"

Text::Text(String string, String fontPath, int size) {
    _string = string;
    _fontPath = fontPath;
    
    _font.loadFromFile(_fontPath);
    
    _drawable.setString(_string);
    _drawable.setCharacterSize(size);
    _drawable.setColor(sf::Color::Black);
    _drawable.setFont(_font);
}

void Text::Update(float dt) {
    
}

void Text::Draw() {
    theWorld.GetWindow().draw(_drawable);
}

void Text::SetString(String string) {
    _string = string;
    _drawable.setString(_string);
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

Text::~Text() {
    
}