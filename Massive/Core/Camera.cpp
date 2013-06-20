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
    _view = new sf::View();
    _view->setSize(960 * 2, 540 * 2);
    _view->setCenter(480 * 2, 270 * 2);
}

Camera::~Camera() {
    
}

Camera &Camera::getInstance() {
    if (s_Camera == NULL) {
        s_Camera = new Camera();
    }
    
    return *s_Camera;
}