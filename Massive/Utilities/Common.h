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
#include <fstream>

typedef std::string			String; //! Shorthand for std::string. Simple as that.
typedef std::set<String>	StringSet; //! Shorthand for a Set of Strings. What did you expect?

#define MD Utility

//! Class used to store little functions that are useful everywhere
class Utility {
public:
    static bool fileExists(String fileName) {
        std::ifstream file(fileName);
        return file.good();
    }
    
    static void createFile(String fileName) {
        if (fileExists(fileName) == false) {
            fopen(fileName.c_str(), "w");
        }
    }
    
    static String readFile(String fileName) {
        if (fileExists(fileName)) {
            std::ifstream file(fileName);
            String content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
            return content;
        }
        else {
            return "";
        }
    }
    
    static void writeToFile(String fileName, String output) {
        std::ofstream file(fileName, std::ios::trunc);
        file << output;
        file.close();
    }
    
    static void appendToFile(String fileName, String output) {
        std::ofstream file(fileName, std::ios::app);
        file << output;
        file.close();
    }
};

#endif
