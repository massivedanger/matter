//
//  Screen.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Screen__
#define __Massive__Screen__

#include "../Utilities/Common.h"

class Screen {
    
public:
    Screen();
    ~Screen();
    virtual void Draw() {}
    virtual void Update(float dt) {}
};

#endif /* defined(__Massive__Screen__) */
