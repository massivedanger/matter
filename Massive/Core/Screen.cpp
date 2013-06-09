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

Screen::~Screen() {
    
}

void Screen::update(float dt) {
    updateEntities(dt);
}

void Screen::draw() {
    drawEntities();
}

void Screen::addEntity(Entity *entity, int layer) {
    if (entity == NULL) {
        // TODO: log error
        return;
    }
    
    entity->layer = layer;
    _layers[layer].push_back(entity);
}

void Screen::addEntityWithLayerName(Entity *entity, const String &layer) {
    addEntity(entity, getLayerByName(layer));
}

void Screen::removeEntity(Entity *entity) {
    // TODO: write this
}

void Screen::updateEntities(float dt) {
    std::map<int, EntityList>::iterator layersIt = _layers.begin();
    while (layersIt != _layers.end()) {
        std::vector<Entity *> entities = layersIt->second;
        for (Entity *e : entities) {
            e->update(dt);
        }
        layersIt++;
    }
}

void Screen::drawEntities() {
    std::map<int, EntityList>::iterator layersIt = _layers.begin();
    while (layersIt != _layers.end()) {
        std::vector<Entity *> entities = layersIt->second;
        for (Entity *e : entities) {
            e->draw();
        }
        layersIt++;
    }
}

void Screen::nameLayer(const String &name, int layerNumber) {
    // TODO: write this
}

const int Screen::getLayerByName(const String& name) {
	std::map<String,int>::iterator it = _layerNames.find(name);
	if (it != _layerNames.end()) {
		return it->second;
	}
	else {
		return 0;
	}
}
