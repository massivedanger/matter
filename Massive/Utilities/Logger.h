//
//  Logger.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Logger__
#define __Massive__Logger__

#include "Common.h"

#define log Logger::GetInstance()

class SquirrelBridge;

class Logger {
    
    friend SquirrelBridge;
    
public:
    Logger();
    ~Logger();
    
    static Logger &getInstance();
    
    void printToConsole(String string);
    void printToFile(String string);
    
    void debug(String string);
    void info(String string);
    void error(String string);
    
    String prefix;
    
protected:
    static Logger *s_Logger;
    String getTimestamp();
    
private:
    String prefixedString(String string);
};

#endif /* defined(__Massive__Logger__) */
