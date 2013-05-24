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
    virtual void Update(float dt) {}
    virtual void Draw() {}
    
    void SetLayer(int layer) { _layer = layer; }
    int GetLayer() { return _layer; }
    
    virtual void SetPosition(int x, int y) {}
    virtual void MovePosition(int x, int y) {}
    virtual sf::Vector2f GetPosition() { return sf::Vector2f(0.0f, 0.0f); }
    
    virtual void SetRotation(float rotation) {}
    virtual void Rotate(float rotation) {}
    virtual float GetRotation() { return 0.f; }
    
    virtual void SetScale(float scaleX, float scaleY) {}
    virtual void Scale(float scaleX, float scaleY) {}
    virtual sf::Vector2f GetScale() { return sf::Vector2f(0.0f, 0.0f); }
    
    virtual void SetOrigin(int x, int y) {}
    virtual sf::Vector2f GetOrigin() { return sf::Vector2f(0.0f, 0.0f); }
    
protected:
    int _layer;
};

typedef std::vector<Entity*>        EntityList;
typedef std::map<int, EntityList>	EntityLayers;

#endif /* defined(__Massive__Entity__) */
