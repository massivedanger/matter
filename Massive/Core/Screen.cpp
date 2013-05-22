//
//  Screen.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Screen.h"

Screen::Screen() {
    
}

void Screen::Update(float dt) {
    UpdateEntities(dt);
}

void Screen::Draw() {

}

void Screen::AddEntity(Entity *entity, int layer) {
    if (entity == NULL) {
        // TODO: log error
        return;
    }
    
    entity->SetLayer(layer);
    _layers[layer].push_back(entity);
}

void Screen::AddEntity(Entity *entity, const String &layer) {
    AddEntity(entity, GetLayerByName(layer));
}

void Screen::UpdateEntities(float dt) {
    std::map<int, EntityList>::iterator layersIt = _layers.begin();
    while (layersIt != _layers.end()) {
        std::vector<Entity *> entities = layersIt->second;
        for (Entity *e : entities) {
            e->Update(dt);
        }
        layersIt++;
    }
}

void Screen::DrawEntities() {
    std::map<int, EntityList>::iterator layersIt = _layers.begin();
    while (layersIt != _layers.end()) {
        std::vector<Entity *> entities = layersIt->second;
        for (Entity *e : entities) {
            e->Draw();
        }
        layersIt++;
    }
}

const int Screen::GetLayerByName(const String& name) {
	std::map<String,int>::iterator it = _layerNames.find(name);
	if (it != _layerNames.end()) {
		return it->second;
	}
	else {
		return 0;
	}
}
