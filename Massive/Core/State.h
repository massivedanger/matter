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
#include "../Messaging/Observer.h"
#include "../Messaging/Message.h"
#include "Screen.h"

class State {
    
public:
    State();
    ~State();
    virtual void draw();
    virtual void update(float dt);
    
    void addScreen(Screen *screen);
    void removeScreen(Screen *screen);
    
private:
    std::set<Screen *> _screens;
    
    
};

#endif /* defined(__Massive__State__) */
