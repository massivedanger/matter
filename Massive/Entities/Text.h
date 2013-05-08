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

class Text : public Actor {
    
public:
    String GetString();
    void SetString(String *string);
};

#endif /* defined(__Massive__Text__) */
