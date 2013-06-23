//
//  Camera.h
//  Massive
//
//  Created by Evan Walsh on 19/6/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Camera__
#define __Massive__Camera__

#include <SFML/Graphics.hpp>

#define theCamera Camera::getInstance()

class Camera {
    
public:
    Camera();
    ~Camera();
    static Camera &getInstance();
    
    void setCenter(int x, int y);
    void move(int x, int y);
    
    void setRotation(float newRotation);
    void rotate(float rotateBy);
    
    void zoom(float newZoom);
    
    sf::View view;
    
protected:
    static Camera *s_Camera;

};

#endif /* defined(__Massive__Camera__) */
