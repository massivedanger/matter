//
//  InputManager.h
//  Massive
//
//  Created by Evan Walsh on 7/6/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__InputManager__
#define __Massive__InputManager__

#define theInput InputManager::getInstance()

#include <SFML/Window.hpp>
#include <array>

#include "../Utilities/Common.h"

class InputManager {
    
public:
    InputManager();
    ~InputManager();
    
    static InputManager &getInstance();
    
    void keyPressed(sf::Event::KeyEvent event);
    void keyReleased(sf::Event::KeyEvent event);
    
    void mouseMoved(int x, int y);
    void mouseWheelMoved(int delta, int x, int y);
    void mouseButtonPressed(sf::Mouse::Button button, int x, int y);
    void mouseButtonReleased(sf::Mouse::Button button, int x, int y);
    
protected:
    static InputManager *s_InputManager;
    
    String mouseButtonToString(int buttonCode);
    String keycodeToString(int keycode);
};

#endif /* defined(__Massive__InputManager__) */
