//
//  Actor.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Actor__
#define __Massive__Actor__

#include "../Utilities/Common.h"
#include "Entity.h"

class Actor : public Entity {
    
public:
    Actor();
    ~Actor();
    virtual void update(float dt);
    virtual void draw();
    
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
    
    virtual void receiveMessage(Message *message);
    
private:
    sf::CircleShape _drawable;

};

#endif /* defined(__Massive__Actor__) */
