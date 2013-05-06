//
//  HUD.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "HUD.h"

HUD::HUD() {
    _layers = HUDLayerSet();
}

HUDLayerSet HUD::GetLayers() {
    return _layers;
}