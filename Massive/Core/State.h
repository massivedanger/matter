//
//  State.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__State__
#define __Massive__State__

#include "../Utilities/Common.h"
#include "Screen.h"

class State {
    
public:
    State();
    ~State();
    void Draw();
    void Update(float dt);
    
};

#endif /* defined(__Massive__State__) */
