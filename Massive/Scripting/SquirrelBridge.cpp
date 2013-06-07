//
//  SquirrelBridge.cpp
//  Massive
//
//  Created by Evan Walsh on 4/6/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "SquirrelBridge.h"
#include "../Massive.h"

SquirrelBridge *SquirrelBridge::s_SquirrelBridge;

SquirrelBridge::SquirrelBridge() {
    sqVM = sq_open(SQUIRREL_STACK_SIZE);
    sqstd_seterrorhandlers(sqVM);
    sq_setprintfunc(sqVM, print, NULL);
    sq_pushroottable(sqVM);
}

SquirrelBridge::~SquirrelBridge() {
    
}

SquirrelBridge &SquirrelBridge::getInstance() {
    if (s_SquirrelBridge == NULL) {
        s_SquirrelBridge = new SquirrelBridge();
    }
    
    return *s_SquirrelBridge;
}

void SquirrelBridge::print(HSQUIRRELVM vm, const SQChar *string, ...) {
    va_list args;
    va_start(args, string);
    vprintf(string, args);
    va_end(args);
}

void SquirrelBridge::init(String mainScriptPath) {
    String error;
    Sqrat::Script mainScript(sqVM);
    
    setupBindings(sqVM);
    
    try {
        mainScript.CompileFile(mainScriptPath);
        mainScript.Run();
    } catch (Sqrat::Exception e) {
        printf("Script error: %s", e.Message().c_str());
    }
}

void SquirrelBridge::setupBindings(HSQUIRRELVM vm) {
    using namespace Sqrat;
    
    Table gTable(vm);
    
    gTable.Bind("Logger", Class<Logger>(vm)
                .Var("prefix", &Logger::prefix)
                .Func("printToConsole", &Logger::printToConsole)
                .StaticFunc("getInstance", &Logger::getInstance)
                .Func("debug", &Logger::debug)
                .Func("info", &Logger::info)
                .Func("error", &Logger::error));
    
    gTable.Bind("World", Class<World>(vm)
                .StaticFunc("getInstance", &World::getInstance)
                .Func("init", &World::init)
                .Func("destroy", &World::destroy)
                .Func("start", &World::start)
                .Func("stop", &World::stop)
                .Func("getDT", &World::getDT)
                .Func("getFPS", &World::getFPS)
                .Func("getFPSString", &World::getFPSString)
                .Func("tickAndDraw", &World::tickAndDraw)
                .Func("tick", &World::tick)
                .Func("draw", &World::draw)
                .Prop("state", &World::getCurrentState, &World::setState)
                .Func("receiveMessage", &World::receiveMessage));
    
    gTable.Bind("Text", Class<Text>(vm)
                .Func("draw", &Text::draw)
                .Func("update", &Text::update)
                .Var("string", &Text::string)
                .Var("fontPath", &Text::fontPath));
    
    gTable.Bind("Constants", ConstTable(vm)
                .Const("DefaultFont", MASSIVE_DEFAULT_FONT));
    
    Sqrat::RootTable(vm).Bind("Massive", gTable);
}