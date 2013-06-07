//
//  Text.h
//  Massive
//
//  Created by Evan Walsh on 8/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Text__
#define __Massive__Text__

#include "../Utilities/Common.h"
#include "Actor.h"
#include <SFML/Graphics.hpp>

//#define MASSIVE_DEFAULT_FONT "Libraries/Meslo LG v1.2.1/MesloLGL-Regular.ttf"
#define MASSIVE_DEFAULT_FONT "/Users/evan/Library/Fonts/MesloLGS-Regular.ttf"

class Text : public Actor {
    
public:
    Text();
    ~Text();
    
    virtual void update(float dt);
    virtual void draw();
    
    String string;
    String fontPath;
    sf::Font font;
    
    float rotation;
    
    virtual void setPosition(int x, int y);
    virtual void movePosition(int x, int y);
    virtual sf::Vector2f getPosition();
    
    virtual void setRotation(float rotation);
    virtual void rotate(float rotation);
    virtual float getRotation();
    
    virtual void setScale(float scaleX, float scaleY);
    virtual void scale(float scaleX, float scaleY);
    virtual sf::Vector2f getScale();
    
    virtual void setOrigin(int x, int y);
    virtual sf::Vector2f getOrigin();
    
private:
    sf::Text _drawable;
};

#endif /* defined(__Massive__Text__) */
