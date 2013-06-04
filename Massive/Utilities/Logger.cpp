//
//  Logger.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Logger.h"
#include <iomanip>

Logger *Logger::s_Logger;

Logger::Logger() {
    _prefix = "[INFO]";
}

Logger::~Logger() {
    
}

Logger &Logger::GetInstance() {
    if (s_Logger == NULL) {
        s_Logger = new Logger();
    }
    
    return *s_Logger;
}

void Logger::PrintToConsole(String string) {
    printf("%s %s\n", Logger::GetTimestamp().c_str(), Logger::PrefixedString(string).c_str());
}

void Logger::PrintToFile(String string) {
    
}

String Logger::GetTimestamp() {
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

String Logger::PrefixedString(String string) {
    if (_prefix != "") {
        return _prefix + " " + string;
    }
    else {
        return string;
    }
}

void Logger::BindSquirrel(HSQUIRRELVM vm) {
    using namespace Sqrat;
    Table massiveTable(vm);
    
    massiveTable.Bind("Logger", Class<Logger>(vm)
                      .Func("SetPrefix", &Logger::SetPrefix)
                      .Func("PrintToConsole", &Logger::PrintToConsole)
                      .Func("GetTimestamp", &Logger::GetTimestamp)
                      .StaticFunc("GetInstance", &Logger::GetInstance)
                      );
    
    RootTable(vm).Bind("Massive", massiveTable);
}
