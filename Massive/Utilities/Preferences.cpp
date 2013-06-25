//
//  Preferences.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Preferences.h"

Preferences *Preferences::s_Preferences;

Preferences::Preferences() {
    _file = sqBridge.preferencesPath + "/config.json";
    MD::createFile(_file);
}

Preferences::~Preferences() {
    
}

Preferences &Preferences::getInstance() {
    if (s_Preferences == 0) {
        s_Preferences = new Preferences();
    }
    
    return *s_Preferences;
}