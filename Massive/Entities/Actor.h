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
    virtual void Update(float dt);
    virtual void Draw();

};

#endif /* defined(__Massive__Actor__) */
