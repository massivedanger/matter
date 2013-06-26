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
    fileName = sqBridge.preferencesPath + "/config.json";
    MD::createFile(fileName);
}

Preferences::~Preferences() {
    
}

Preferences &Preferences::getInstance() {
    if (s_Preferences == 0) {
        s_Preferences = new Preferences();
    }
    
    return *s_Preferences;
}

void Preferences::write(String json) {
    MD::writeToFile(fileName, json);
}

String Preferences::read() {
    return MD::readFile(fileName);
}

