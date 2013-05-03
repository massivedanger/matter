//
//  Signal.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Signal.h"

Signal *Signal::s_signal;

Signal::Signal() {
    
}

Signal& Signal::GetInstance() {
    if (!s_signal) {
        s_signal = new Signal();
    }
    
//    return s_signal;
}