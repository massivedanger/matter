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
    
    sf::View getView() { return *_view; }
    
protected:
    static Camera *s_Camera;
    
private:
    sf::View *_view;
};

#endif /* defined(__Massive__Camera__) */
