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

/*!
 *  Get the singleton instance of Logger for the game
 */
Logger &Logger::getInstance() {
    if (s_Logger == NULL) {
        s_Logger = new Logger();
    }
    
    return *s_Logger;
}

/*!
 *  Print message to console with a prefix
 */
void Logger::printToConsole(String string) {
    printf("%s %s\n", Logger::getTimestamp().c_str(), Logger::prefixedString(string).c_str());
}


/*!
 *  Print message to logfile with prefix
 */
void Logger::printToFile(String string) {
    
}

/*!
 *  Print debug line to console
 */
void Logger::debug(String string) {
    prefix = "[DEBUG]";
    printToConsole(string);
}

/*!
 *  Print info line to console
 */
void Logger::info(String string) {
    prefix = "[INFO]";
    printToConsole(string);
}

/*!
 *  Print error line to console
 */
void Logger::error(String string) {
    prefix = "[ERROR]";
    printToConsole(string);
}

#pragma mark - Protected

/*!
 *  Get timestamp with format [HH:MM:SS TIMEZONE]
 */
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

#pragma mark - Private

/*!
 *  Get string with currently-stored logger prefix
 */
String Logger::prefixedString(String string) {
    if (prefix != "") {
        return prefix + " " + string;
    }
    else {
        return string;
    }
}
