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

class Logger {
    
public:
    Logger();
    ~Logger();
    
    static Logger &GetInstance();
    
    void PrintToConsole(String string);
    void PrintToFile(String string);
    
    void SetPrefix(String prefix) { _prefix = prefix; }
    String GetPrefix() { return _prefix; }
    
protected:
    static Logger *s_Logger;
    String GetTimestamp();
    
private:
    String PrefixedString(String string);
    
    String _prefix;
};

#endif /* defined(__Massive__Logger__) */
