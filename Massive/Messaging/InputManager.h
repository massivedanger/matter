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

class InputManager {
    
public:
    static InputManager &getInstance();
    
    void keyPressed(sf::Event::KeyEvent event);
    void keyReleased(sf::Event::KeyEvent event);
    
    void mouseMoved(int x, int y);
    void mouseWheelMoved(int delta, int x, int y);
    void mouseButtonPressed(sf::Mouse::Button button, int x, int y);
    void mouseButtonReleased(sf::Mouse::Button button, int x, int y);
    
protected:
    InputManager();
    ~InputManager();
    static InputManager *s_InputManager;
};

#endif /* defined(__Massive__InputManager__) */
