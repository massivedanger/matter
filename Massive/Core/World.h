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

class Entity;
class HUD;

#define theWorld World::GetInstance()

class World : public Listener {
public:
    static World &GetInstance();
    
    bool Init(unsigned int windowWidth = 960, unsigned int windowHeight = 600, String windowTitle = "Massive Game", bool fullscreen = false);
    void Destroy();
    
    void Start();
    void Stop();
    
    const float GetDelta();
    void TickAndRender();
    void Tick();
    void Render();
    
    void Add(Entity *entity, const String &layer);
    void Remove(Entity *entity);
    
    void NameLayer(const String &name, int layerNumber);
    void GetLayerByName(const String &name);
    EntityLayers& GetLayers() { return _layers; }
    
    State* GetCurrentState() { return _state; }
    
    virtual void ReceiveMessage(Message *message);
    
protected:
    World();
    static World *s_World;
    float CalculateNewDT();
    void UpdateEntities(float frameDT);
    void CleanupEntities();
    
private:
    struct EntityLayerPair
    {
        Entity *entity;
        int _layer;
    };
    
    EntityLayers _layers;
    State *_state;

    std::map<String, int> _layerNames;
    
    bool _running;
    bool _initialized;
    float _lastTime;
    float _currentTime;
    float _dt;
    
    ~World();
};


#endif /* defined(__Massive__World__) */
