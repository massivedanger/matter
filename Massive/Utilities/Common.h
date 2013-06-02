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

typedef std::string			String; //! Shorthand for std::string. Simple as that.
typedef std::set<String>	StringSet; //! Shorthand for a Set of Strings. What did you expect?

#define M Utility

//! Class used to store little functions that are useful everywhere
class Utility {
    
public:
    //! Get String representation of a float
    static String floatToString(float number) {
        std::ostringstream stream;
        stream << number;
        return stream.str();
    }
};

#endif
