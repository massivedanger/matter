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
#include "../Entities/Entity.h"

class Screen {
    
public:
    Screen();
    ~Screen();
    virtual void Draw();
    virtual void Update(float dt);
    
    void AddEntity(Entity *entity, int layer);
    void AddEntity(Entity *entity, const String &layer);
    void RemoveEntity(Entity *entity);
    
    void NameLayer(const String &name, int layerNumber);
    const int GetLayerByName(const String &name);
    EntityLayers& GetLayers() { return _layers; }
    
protected:
    void UpdateEntities(float dt);
    void DrawEntities();
    void CleanupEntities();
    
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
