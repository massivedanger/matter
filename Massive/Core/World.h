//
//  World.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__World__
#define __Massive__World__

#include "../Utilities/Common.h"
#include "../Utilities/Logger.h"
#include "../Messaging/Message.h"
#include "../Entities/Entity.h"
#include "State.h"

#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>
#include <sqrat.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class HUD;

#define theWorld World::GetInstance()

class World : public Listener {
public:
    static World &GetInstance();
    
    bool Init(unsigned int windowWidth = 960, unsigned int windowHeight = 600, String windowTitle = "Massive Game", bool fullscreen = false, bool antialias = true);
    void Destroy();
    
    void Start();
    void Stop();
    
    const float GetDT() { return _dt; } //! Get the current frame's Delta-Time
    const float GetFPS() { return _lastFPS; } //! Get the current second's stored FPS
    const String GetFPSString();
    void TickAndDraw();
    void Tick();
    void Draw();
    
    void SetState(State *state) { _state = state; } //! Set active State
    State* GetCurrentState() { return _state; } //! Get active State
    
    sf::RenderWindow &GetWindow() { return _window; } //! Get SFML RenderWindow
    sf::ContextSettings &GetContextSettings() { return _contextSettings; } //! Get SFML ContextSettings
    
    virtual void ReceiveMessage(Message *message);
    
    HSQUIRRELVM GetSquirrelVM() { return _squirrelVM; };
    
protected:
    World();
    static World *s_World;
    void UpdateFPS();
    float UpdateDT();
    
private:
    ~World();
    static void sq_print(HSQUIRRELVM vm, const SQChar *string, ...);
    
    State *_state;
    
    HSQUIRRELVM _squirrelVM;
    
    sf::RenderWindow _window;
    sf::Clock _clock;
    sf::ContextSettings _contextSettings;
    
    bool _running;
    bool _initialized;
    bool _antialiased;
    float _lastTime;
    float _currentTime;
    
    float _dt;
    
    float _fps;
    float _lastFPS;
    float _lastFPSTime;
};


#endif /* defined(__Massive__World__) */
