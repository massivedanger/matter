//
//  HUD.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__HUD__
#define __Massive__HUD__

#include "../Utilities/Common.h"
#include "HUDLayer.h"

typedef std::set<HUDLayer *> HUDLayerSet;

class HUD {
    
public:
    HUD();
    HUDLayerSet GetLayers();
    bool PushLayer(HUDLayer *layer);
    bool UnshiftLayer(HUDLayer *layer);
    HUDLayer PopLayer();
    HUDLayer ShiftLayer();
    
private:
    std::set<HUDLayer *> _layers;
};

#endif /* defined(__Massive__HUD__) */
