//
//  Preferences.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Preferences__
#define __Massive__Preferences__

#define thePrefs Preferences::getInstance()

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include "Common.h"
#include "Logger.h"
#include "../Scripting/SquirrelBridge.h"

class Preferences {
    
public:
    Preferences();
    ~Preferences();
    static Preferences &getInstance();
    
    void write(String json);
    String read();
    
    String fileName;
    
protected:
    static Preferences *s_Preferences;

};

#endif /* defined(__Massive__Preferences__) */
