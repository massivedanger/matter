//
//  HUD.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "HUD.h"

HUD::HUD() {
    layers = HUDLayerSet();
}

HUD::~HUD() {
    
}

bool HUD::pushLayer(HUDLayer *layer) {
    // TODO: write this
    return true;
}

bool HUD::unshiftLayer(HUDLayer *layer) {
    // TODO: write this
    return true;
}

HUDLayer HUD::popLayer() {
    // TODO: write this
    return HUDLayer();
}

HUDLayer HUD::shiftLayer() {
    // TODO: write this
    return HUDLayer();
}