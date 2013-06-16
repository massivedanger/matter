//
//  Screen.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Screen__
#define __Massive__Screen__

#include "../Utilities/Common.h"
#include "../Utilities/Logger.h"
#include "../Entities/Entity.h"

class Screen {
    
public:
    Screen();
    ~Screen();
    virtual void draw();
    virtual void update(float dt);
    
    void addEntity(Entity *entity, int layer);
    void addEntityWithLayerName(Entity *entity, const String &layer);
    void removeEntity(Entity *entity);
    
    void nameLayer(const String &name, int layerNumber);
    const int getLayerByName(const String &name);
    EntityLayers& getLayers() { return _layers; }
    
protected:
    void updateEntities(float dt);
    void drawEntities();
    void cleanupEntities();
    
private:
    std::map<String, int> _layerNames;
    
    struct EntityLayerPair
    {
        Entity *entity;
        int _layer;
    };
    
    EntityLayers _layers;
};

#endif /* defined(__Massive__Screen__) */
