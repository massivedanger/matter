//
//  Camera.cpp
//  Massive
//
//  Created by Evan Walsh on 19/6/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Camera.h"

Camera *Camera::s_Camera;

Camera::Camera() {
    view = sf::View(sf::Vector2f(480.f * 2, 270.f * 2), sf::Vector2f(960.f * 2, 540.f * 2));
}

Camera::~Camera() {
    
}

Camera &Camera::getInstance() {
    if (s_Camera == NULL) {
        s_Camera = new Camera();
    }
    
    return *s_Camera;
}

void Camera::setCenter(int x, int y) {
    view.setCenter(x, y);
}

void Camera::move(int x, int y) {
    view.move(x, y);
}

void Camera::setRotation(float newRotation) {
    view.setRotation(newRotation);
}

void Camera::rotate(float rotateBy) {
    view.rotate(rotateBy);
}

void Camera::zoom(float newZoom) {
    view.zoom(newZoom);
}

