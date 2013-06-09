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
    
    gTable.Bind("State", Class<State>(vm)
                .Func("draw", &State::draw)
                .Func("update", &State::update)
                .Func("addScreen", &State::addScreen)
                .Func("removeScreen", &State::removeScreen));
    
    gTable.Bind("Screen", Class<Screen>(vm)
                .Func("draw", &Screen::draw)
                .Func("update", &Screen::update)
                .Func("addEntity", &Screen::addEntity)
                .Func("addEntityWithLayerName", &Screen::addEntityWithLayerName)
                .Func("removeEntity", &Screen::removeEntity)
                .Func("nameLayer", &Screen::nameLayer)
                .Func("getLayerByName", &Screen::getLayerByName)
                .Func("getLayers", &Screen::getLayers));
    
    gTable.Bind("Entity", Class<Entity>(vm)
                .Var("layer", &Entity::layer)
                .Func("update", &Entity::update)
                .Func("draw", &Entity::draw)
                .Func("setPosition", &Entity::setPosition)
                .Func("movePosition", &Entity::movePosition)
                .Func("getPosition", &Entity::getPosition)
                .Func("setRotation", &Entity::setRotation)
                .Func("rotate", &Entity::rotate)
                .Func("getRotation", &Entity::getRotation)
                .Func("setScale", &Entity::setScale)
                .Func("scale", &Entity::scale)
                .Func("getScale", &Entity::getScale)
                .Func("setOrigin", &Entity::setOrigin)
                .Func("getOrigin", &Entity::getOrigin));
    
    gTable.Bind("Text", Class<Text>(vm)
                .Func("draw", &Text::draw)
                .Func("update", &Text::update)
                .Var("string", &Text::string)
                .Var("fontPath", &Text::fontPath));
    
    gTable.Bind("Actor", Class<Actor>(vm)
                .Func("draw", &Actor::draw)
                .Func("update", &Actor::update));
    
    gTable.Bind("Light", Class<Light>(vm)
                .Func("draw", &Light::draw)
                .Func("update", &Light::update));
    
    gTable.Bind("Constants", ConstTable(vm)
                .Const("DefaultFont", MASSIVE_DEFAULT_FONT));
    
    Sqrat::RootTable(vm).Bind("Massive", gTable);
}