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
    ~HUD();
    HUDLayerSet layers;
    bool pushLayer(HUDLayer *layer);
    bool unshiftLayer(HUDLayer *layer);
    HUDLayer popLayer();
    HUDLayer shiftLayer();

};

#endif /* defined(__Massive__HUD__) */
