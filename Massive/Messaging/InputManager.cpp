//
//  InputManager.cpp
//  Massive
//
//  Created by Evan Walsh on 7/6/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "InputManager.h"
#include "../Utilities/Common.h"
#include "../Utilities/Logger.h"
#include "../Scripting/SquirrelBridge.h"
#include "Observer.h"

InputManager *InputManager::s_InputManager;

InputManager::InputManager() {
    
}

InputManager::~InputManager() {
    
}

InputManager &InputManager::getInstance() {
    if (s_InputManager == NULL) {
        s_InputManager = new InputManager();
    }
    
    return *s_InputManager;
}

void InputManager::keyPressed(sf::Event::KeyEvent event) {
    Message *keyMessage = new Message("massive:key:pressed");
    keyMessage->json = "{\"key\": \"" + keycodeToString(event.code) + "\"}";
    theObserver.broadcast(keyMessage);
}

void InputManager::keyReleased(sf::Event::KeyEvent event) {
    Message *keyMessage = new Message("massive:key:released");
    keyMessage->json = "{\"key\": \"" + keycodeToString(event.code) + "\"}";
    theObserver.broadcast(keyMessage);
    if (keycodeToString(event.code) == "escape") {
        log.script("Reloading main script...");
        sqBridge.reload();
    }
}

void InputManager::mouseMoved(int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:moved");
    mouseMessage->json = "{\"x\": \"" + std::to_string(x) + "\", \"y\": \"" + std::to_string(y) + "\"}";
    theObserver.broadcast(mouseMessage);
}

void InputManager::mouseWheelMoved(int delta, int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:wheel-moved");
    mouseMessage->json = "{\"x\": " + std::to_string(x) + ", \"y\": " + std::to_string(y) + ", \"delta\": " + std::to_string(delta) + "}";
    theObserver.broadcast(mouseMessage);
}

void InputManager::mouseButtonPressed(sf::Mouse::Button button, int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:pressed");
    mouseMessage->json = "{\"button\": \"" + mouseButtonToString(button) + "\", \"x\": \"" + std::to_string(x) + "\", \"y\": \"" + std::to_string(y) + "\"}";
    theObserver.broadcast(mouseMessage);
}

void InputManager::mouseButtonReleased(sf::Mouse::Button button, int x, int y) {
    Message *mouseMessage = new Message("massive:mouse:released");
    mouseMessage->json = "{\"button\": \"" + mouseButtonToString(button) + "\", \"x\": \"" + std::to_string(x) + "\", \"y\": \"" + std::to_string(y) + "\"}";
    theObserver.broadcast(mouseMessage);
}

String InputManager::mouseButtonToString(int buttonCode) {
    String button;
    
    switch (buttonCode) {
        case 0: button = "left"; break;
        case 1: button = "right"; break;
        case 2: button = "middle"; break;
        case 3: button = "button-4"; break;
        case 4: button = "button-5"; break;
        default: button = ""; break;
    }
    
    return button;
}

String InputManager::keycodeToString(int keycode) {
    String key;
    
    switch (keycode) {
        case 0: key = "a"; break;
        case 1: key = "b"; break;
        case 2: key = "c"; break;
        case 3: key = "d"; break;
        case 4: key = "e"; break;
        case 5: key = "f"; break;
        case 6: key = "g"; break;
        case 7: key = "h"; break;
        case 8: key = "i"; break;
        case 9: key = "j"; break;
        case 10: key = "k"; break;
        case 11: key = "l"; break;
        case 12: key = "m"; break;
        case 13: key = "n"; break;
        case 14: key = "o"; break;
        case 15: key = "p"; break;
        case 16: key = "q"; break;
        case 17: key = "r"; break;
        case 18: key = "s"; break;
        case 19: key = "t"; break;
        case 20: key = "u"; break;
        case 21: key = "v"; break;
        case 22: key = "w"; break;
        case 23: key = "x"; break;
        case 24: key = "y"; break;
        case 25: key = "z"; break;
        case 26: key = "0"; break;
        case 27: key = "1"; break;
        case 28: key = "2"; break;
        case 29: key = "3"; break;
        case 30: key = "4"; break;
        case 31: key = "5"; break;
        case 32: key = "6"; break;
        case 33: key = "7"; break;
        case 34: key = "8"; break;
        case 35: key = "9"; break;
        case 36: key = "escape"; break;
        case 37: key = "l-control"; break;
        case 38: key = "l-shift"; break;
        case 39: key = "l-alt"; break;
        case 40: key = "l-system"; break;
        case 41: key = "r-control"; break;
        case 42: key = "r-shift"; break;
        case 43: key = "r-alt"; break;
        case 44: key = "r-system"; break;
        case 45: key = "menu"; break;
        case 46: key = "["; break;
        case 47: key = "]"; break;
        case 48: key = ";"; break;
        case 49: key = ","; break;
        case 50: key = "."; break;
        case 51: key = "'"; break;
        case 52: key = "/"; break;
        case 53: key = "\\"; break;
        case 54: key = "`"; break;
        case 55: key = "="; break;
        case 56: key = "-"; break;
        case 57: key = "space"; break;
        case 58: key = "return"; break;
        case 59: key = "backspace"; break;
        case 60: key = "tab"; break;
        case 61: key = "page-up"; break;
        case 62: key = "page-down"; break;
        case 63: key = "end"; break;
        case 64: key = "home"; break;
        case 65: key = "insert"; break;
        case 66: key = "delete"; break;
        case 67: key = "add"; break;
        case 68: key = "subtract"; break;
        case 69: key = "multiply"; break;
        case 70: key = "divide"; break;
        case 71: key = "left"; break;
        case 72: key = "right"; break;
        case 73: key = "up"; break;
        case 74: key = "down"; break;
        case 75: key = "numpad-0"; break;
        case 76: key = "numpad-1"; break;
        case 77: key = "numpad-2"; break;
        case 78: key = "numpad-3"; break;
        case 79: key = "numpad-4"; break;
        case 80: key = "numpad-5"; break;
        case 81: key = "numpad-6"; break;
        case 82: key = "numpad-7"; break;
        case 83: key = "numpad-8"; break;
        case 84: key = "numpad-9"; break;
        case 85: key = "f1"; break;
        case 86: key = "f2"; break;
        case 87: key = "f3"; break;
        case 88: key = "f4"; break;
        case 89: key = "f5"; break;
        case 90: key = "f6"; break;
        case 91: key = "f7"; break;
        case 92: key = "f8"; break;
        case 93: key = "f9"; break;
        case 94: key = "f10"; break;
        case 95: key = "f11"; break;
        case 96: key = "f12"; break;
        case 97: key = "f13"; break;
        case 98: key = "f14"; break;
        case 99: key = "f15"; break;
        case 100: key = "pause"; break;
        default: key = ""; break;
    }
    
    return key;
}

