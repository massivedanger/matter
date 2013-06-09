//
//  Light.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Light__
#define __Massive__Light__

#include "../Utilities/Common.h"
#include "Entity.h"

class Light : public Entity {
    
public:
    Light();
    ~Light();
    virtual void update(float dt);
    virtual void draw();
    
};

#endif /* defined(__Massive__Light__) */
