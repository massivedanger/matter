//
//  main.cpp
//  thelasterror
//
//  Created by Evan Walsh on 1/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Massive.h"

int main(int argc, const char * argv[])
{
    
    theWorld.Init();
    theWorld.Start();
    theWorld.Stop();
    
    return 0;
}
