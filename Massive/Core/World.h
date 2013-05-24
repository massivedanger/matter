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
#include "../Messaging/Message.h"
#include "../Entities/Entity.h"
#include "State.h"

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
    
    const float GetDT();
    const float GetFPS();
    const String GetFPSString();
    void TickAndDraw();
    void Tick();
    void Draw();
    
    void SetState(State *state) { _state = state; }
    State* GetCurrentState() { return _state; }
    
    sf::RenderWindow &GetWindow() { return _window; }
    sf::ContextSettings &GetContextSettings() { return _contextSettings; }
    
    virtual void ReceiveMessage(Message *message);
    
protected:
    World();
    static World *s_World;
    void UpdateFPS();
    float UpdateDT();
    
private:
    ~World();
    
    State *_state;
    
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
