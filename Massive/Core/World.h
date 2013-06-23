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
#include "../Messaging/Observer.h"
#include "../Messaging/Message.h"
#include "../Messaging/InputManager.h"
#include "../Entities/Entity.h"
#include "State.h"
#include "Camera.h"

#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>
#include <sqrat.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class HUD;

#define theWorld World::getInstance()

class World : public Listener {
    
public:
    World();
    ~World();
    static World &getInstance();
    
    bool init(unsigned int windowWidth = 960, unsigned int windowHeight = 600, String windowTitle = "Massive Game", bool fullscreen = false, bool antialias = true);
    void destroy();
    
    void start();
    void stop();
    
    const float getDT() { return _dt; } //! Get the current frame's Delta-Time
    const float getFPS() { return _lastFPS; } //! Get the current second's stored FPS
    const String getFPSString();
    void tickAndDraw();
    void tick();
    void draw();
    
    void setState(State *state) { _state = state; } //! Set active State
    State* getCurrentState() { return _state; } //! Get active State
    
    sf::RenderWindow &getWindow() { return *_window; } //! Get SFML RenderWindow
    sf::ContextSettings &getContextSettings() { return *_contextSettings; } //! Get SFML ContextSettings
    
    void updateViewWithCamera(Camera *camera);
    bool isHighRes() { return _highRes; } //! Returns `true` if the display is HiDPI
    int scaleFactor();
    
    void lostFocus();
    void gainedFocus();
    void resized();
    
    virtual void receiveMessage(Message *message);
    
    Camera *camera;
    
protected:
    static World *s_World;
    void updateFPS();
    float updateDT();
    
private:
    State *_state;
    bool _highRes;
    
    sf::RenderWindow *_window;
    sf::Clock _clock;
    sf::ContextSettings *_contextSettings;
    
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
