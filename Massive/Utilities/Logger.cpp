//
//  Logger.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Logger.h"
#include "../Scripting/SquirrelBridge.h"
#include <iomanip>

Logger *Logger::s_Logger;

Logger::Logger() {
    prefix = "[INFO]";
}

Logger::~Logger() {
    
}

Logger &Logger::getInstance() {
    if (s_Logger == NULL) {
        s_Logger = new Logger();
    }
    
    return *s_Logger;
}

void Logger::printToConsole(String string) {
    printf("%s %s\n", Logger::getTimestamp().c_str(), Logger::prefixedString(string).c_str());
}

void Logger::printToFile(String string) {
    
}

String Logger::getTimestamp() {
    time_t timer = time(NULL);
    struct tm *timestamp = localtime(&timer);
    std::ostringstream stream;

    stream << "[";
    stream << std::setw(2) << std::setfill('0') << timestamp->tm_hour << ":";
    stream << std::setw(2) << std::setfill('0') << timestamp->tm_min << ":";
    stream << std::setw(2) << std::setfill('0') << timestamp->tm_sec << " ";
    stream << timestamp->tm_zone;
    stream << "]";
    
    return stream.str();
}

String Logger::prefixedString(String string) {
    if (prefix != "") {
        return prefix + " " + string;
    }
    else {
        return string;
    }
}
