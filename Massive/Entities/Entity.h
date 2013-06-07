//
//  Entity.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Entity__
#define __Massive__Entity__

#include "../Utilities/Common.h"
#include <SFML/Graphics.hpp>

class Entity {
    friend class World;
    
public:
    Entity();
    ~Entity();
    
    int layer;
    
    virtual void update(float dt) {}
    virtual void draw() {}
    
    virtual void setPosition(int x, int y) {}
    virtual void movePosition(int x, int y) {}
    virtual sf::Vector2f getPosition() { return sf::Vector2f(0.0f, 0.0f); }
    
    virtual void setRotation(float rotation) {}
    virtual void rotate(float rotation) {}
    virtual float getRotation() { return 0.f; }
    
    virtual void setScale(float scaleX, float scaleY) {}
    virtual void scale(float scaleX, float scaleY) {}
    virtual sf::Vector2f getScale() { return sf::Vector2f(0.0f, 0.0f); }
    
    virtual void setOrigin(int x, int y) {}
    virtual sf::Vector2f getOrigin() { return sf::Vector2f(0.0f, 0.0f); }
};

typedef std::vector<Entity*>        EntityList;
typedef std::map<int, EntityList>	EntityLayers;

#endif /* defined(__Massive__Entity__) */
