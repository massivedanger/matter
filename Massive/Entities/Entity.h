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

class Entity {
    friend class World;
    
public:
    virtual ~Entity();
    virtual void Update(float dt) {}
    virtual void Render() {}
    int GetLayer() { return _layer; }
    
protected:
    int _layer;
};

typedef std::vector<Entity*>        EntityList;
typedef std::map<int, EntityList>	EntityLayers;

#endif /* defined(__Massive__Entity__) */
