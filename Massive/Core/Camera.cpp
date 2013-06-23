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
    view = sf::View();
    scale = 1;
}

Camera::~Camera() {
    
}

Camera &Camera::getInstance() {
    if (s_Camera == NULL) {
        s_Camera = new Camera();
    }
    
    return *s_Camera;
}

void Camera::setSize(int width, int height) {
    view.setSize(width * scale, height * scale);
}

void Camera::setCenter(int x, int y) {
    view.setCenter(x * scale, y * scale);
}

void Camera::move(int x, int y) {
    view.move(x * scale, y * scale);
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

