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
    
    sq_setprintfunc(sqVM, print, NULL);
    sq_pushroottable(sqVM);
//    registerGlobalFunc(sqVM, jsonize, "jsonize");
    
    sqstd_register_bloblib(sqVM);
    sqstd_register_iolib(sqVM);
    sqstd_register_stringlib(sqVM);
    sqstd_register_systemlib(sqVM);
    sqstd_register_mathlib(sqVM);
    sqstd_seterrorhandlers(sqVM);
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

void SquirrelBridge::init(String gameScriptPath, String gamePrefsPath) {
    scriptPath = gameScriptPath;
    preferencesPath = gamePrefsPath;
    
    String error;
    Sqrat::Script mainScript(sqVM);
    
    setupBindings(sqVM);
    runScript("ext.nut");
    runScript("main.nut");
}

void SquirrelBridge::reload() {
    log.todo("Actually implement script reloading");
    log.script("Reloaded.");
}

void SquirrelBridge::runScript(String scriptToRun) {
    if (scriptPath != "") {
        Sqrat::Script script(sqVM);
        if (MD::fileExists(scriptPath + "/" + scriptToRun)) {
            try {
                script.CompileFile(scriptPath + "/" + scriptToRun);
                script.Run();
            } catch (Sqrat::Exception e) {
                log.script("Error: " + e.Message());
            }
        }
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
                .Func("error", &Logger::error)
                .Func("script", &Logger::script)
                .Func("withPrefix", &Logger::withPrefix));
    
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
                .Func("receiveMessage", &World::receiveMessage)
                .Func("updateViewWithCamera", &World::updateViewWithCamera)
                .Var("camera", &World::camera));
    
    gTable.Bind("Camera", Class<Camera>(vm)
                .StaticFunc("getInstance", &Camera::getInstance)
                .Func("setCenter", &Camera::setCenter)
                .Func("move", &Camera::move)
                .Func("setRotation", &Camera::setRotation)
                .Func("rotate", &Camera::rotate)
                .Func("zoom", &Camera::zoom));
    
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
                .Prop("string", &Text::getString, &Text::setString)
                .Func("setPosition", &Text::setPosition));
    
    gTable.Bind("Actor", Class<Actor>(vm)
                .Func("draw", &Actor::draw)
                .Func("update", &Actor::update)
                .Func("setPosition", &Actor::setPosition));
    
    gTable.Bind("Light", Class<Light>(vm)
                .Func("draw", &Light::draw)
                .Func("update", &Light::update));
    
    gTable.Bind("HUD", Class<HUD>(vm)
                .Var("layers", &HUD::layers)
                .Func("pushLayer", &HUD::pushLayer)
                .Func("unshiftLayer", &HUD::unshiftLayer)
                .Func("popLayer", &HUD::popLayer)
                .Func("shiftLayer", &HUD::shiftLayer));
    
    gTable.Bind("InputManager", Class<InputManager>(vm)
                .StaticFunc("getInstance", InputManager::getInstance)
                .Func("keyPressed", &InputManager::keyPressed)
                .Func("keyReleased", &InputManager::keyReleased)
                .Func("mouseMoved", &InputManager::mouseMoved)
                .Func("mouseWheelMoved", &InputManager::mouseWheelMoved)
                .Func("mouseButtonPressed", &InputManager::mouseButtonPressed)
                .Func("mouseButtonReleased", &InputManager::mouseButtonReleased));
    
    gTable.Bind("Observer", Class<Observer>(vm)
                .StaticFunc("getInstance", &Observer::getInstance)
                .Func("broadcast", &Observer::broadcast)
                .Func("subscribe", &Observer::subscribe)
                .Func("unsubscribe", &Observer::unsubscribe)
                .Func("getSubscribersFor", &Observer::getSubscribersFor)
                .Func("getSubscriptionsFor", &Observer::getSubscriptionsFor)
                .Func("sendAll", &Observer::sendAll));
        
    gTable.Bind("Message", Class<Message>(vm)
                .Var("name", &Message::name)
                .Var("json", &Message::json));
    
    gTable.Bind("Listener", Class<Listener>(vm)
                .Func("receiveMessage", &Listener::receiveMessage));
    
    gTable.Bind("SquirrelBridge", Class<SquirrelBridge>(vm)
                .StaticFunc("getInstance", SquirrelBridge::getInstance)
                .Func("runScript", &SquirrelBridge::runScript)
                .Var("scriptPath", &SquirrelBridge::scriptPath)
                .Var("preferencesPath", &SquirrelBridge::preferencesPath));
    
    gTable.Bind("Utility", Class<Utility>(vm)
                .StaticFunc("readFile", &Utility::readFile));
    
    gTable.Bind("Preferences", Class<Preferences>(vm)
                .StaticFunc("getInstance", Preferences::getInstance));
    
    gTable.Bind("Constants", ConstTable(vm)
                .Const("DefaultFont", MASSIVE_DEFAULT_FONT));
    
    Sqrat::RootTable(vm).Bind("Massive", gTable);
}

void registerGlobalFunc(HSQUIRRELVM vm, SQFUNCTION function, const char *functionName) {
    sq_pushroottable(vm);
    sq_pushstring(vm, functionName, -1);
    sq_newclosure(vm, function, 0); //create a new function
    sq_createslot(vm, -3);
    sq_pop(vm, 1); //pops the root table
}

int SquirrelBridge::jsonizeInternal(HSQUIRRELVM v, String &result) {
    int r = 1;
    bool just_begin ;
    const size_t RESERVE_SIZE = 30;
    char buf[RESERVE_SIZE];
    result = "";
    int i;
    /* top of the stack is the object to be jsonized */
    switch(sq_gettype(v, -1))
    {
        case OT_STRING:
        {
            const SQChar *t;
            sq_getstring(v, -1, &t); /* now t will be zero terminated */
            result = std::string("\"") + t + "\"";
            break;
        }
            
        case OT_INTEGER:
        {
            SQInteger i2;
            sq_getinteger(v, -1, &i2);
            snprintf(buf, sizeof(buf), "%d", (int) i2);
            buf[sizeof(buf) - 1] = 0;
            result = buf;
            break;
        }
        case OT_FLOAT:
        {
            SQFloat f;
            sq_getfloat(v, -1, &f);
            snprintf(buf, sizeof(buf), "%f", f);
            buf[sizeof(buf) - 1] = 0;
            result = buf;
            break;
        }
        case OT_BOOL:
        {
            SQBool b;
            sq_getbool(v, -1, &b);
            if (b)
                strncpy(buf, "true", sizeof(buf));
            else
                strncpy(buf, "false", sizeof(buf));
            buf[sizeof(buf) - 1] = 0;
            result = buf;
            break;
        }
            
        case OT_NULL:
            result = "null";
            break;
            
        case OT_ARRAY:
        {
            result = " [ ";
            std::string estr;
            sq_pushnull(v);
            just_begin = true;
            while (SQ_SUCCEEDED(sq_next(v, -2)))
            {
                if (just_begin == false)
                    result += ", ";
                else just_begin = false;
                
                /* top of stack is the array element */
                if (!jsonizeInternal(v, estr))
                {
                    r = 0;
                }
                else
                    result += estr;
                sq_pop(v,2); //pops key and val before the nex iteration
            }
            result += " ] ";
            sq_pop(v, 1);
            break;
            
        }
            
        case OT_TABLE:
        {
            result = " { ";
            sq_pushnull(v);
            just_begin = true;
            while (SQ_SUCCEEDED(sq_next(v, -2)))
            {
                if (just_begin == false)
                    result += ", ";
                else just_begin = false;
                
                /* top of stack is the value */
                /* below the value in the stack is the key */
                std::string value, key;
                i = jsonizeInternal(v, value);
                if (i == 0)
                    r = 0;
                sq_pop(v, 1); // pop value
                if (r)
                {
                    i = jsonizeInternal(v, key);
                    if (i == 0)
                        r = 0;
                }
                sq_pop(v, 1); //pops key
                
                result += key + ": " + value;
            }
            result += " } ";
            sq_pop(v, 1);
            break;
            
        }
            
        default:
            r = 0;/* jsonize failed; cannot convert */
            break;
    }
    return r;
}

SQInteger SquirrelBridge::jsonize(HSQUIRRELVM vm) {
    std::string result;
    int nargs = sq_gettop(vm);
    if (nargs != 2)
    /* invalid pamameters sent into function */
        return sq_throwerror(vm, "invalid number of parameters");
    int r = jsonizeInternal(vm, result);
    if (r)
        sq_pushstring(vm, result.c_str(), result.length());
    else sq_pushnull(vm);
    return 1;
    
}

