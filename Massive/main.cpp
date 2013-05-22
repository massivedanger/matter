//
//  main.cpp
//  thelasterror
//
//  Created by Evan Walsh on 1/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Massive.h"

int main(int argc, const char * argv[])
{
    
    theWorld.Init();
    theWorld.Start();
    
    State *state = new State();
    theWorld.SetState(state);
    
    theWorld.Stop();
    
    return 0;
}
