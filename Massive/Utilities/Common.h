//
//  Common.h
//  Massive
//
//  Created by Evan Walsh on 4/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef Massive_Common_h
#define Massive_Common_h

#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>

typedef std::string			String;
typedef std::set<String>	StringSet;

#define M Utility

class Utility {
    
public:
    static String floatToString(float number) {
        std::ostringstream stream;
        stream << number;
        return stream.str();
    }
};

#endif
