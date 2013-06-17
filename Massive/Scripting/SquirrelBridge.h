//
//  SquirrelBridge.h
//  Massive
//
//  Created by Evan Walsh on 4/6/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__SquirrelBridge__
#define __Massive__SquirrelBridge__

#include <squirrel.h>
#include <sqstdblob.h>
#include <sqstdio.h>
#include <sqstdstring.h>
#include <sqstdsystem.h>
#include <sqstdmath.h>
#include <sqstdaux.h>
#include <sqrat.h>

#include "../Utilities/Common.h"

#define SQUIRREL_STACK_SIZE 1024
#define sqBridge SquirrelBridge::getInstance()

class SquirrelBridge {
    
public:
    SquirrelBridge();
    ~SquirrelBridge();
    static SquirrelBridge &getInstance();
    
    HSQUIRRELVM sqVM;
    
    void init(String mainScriptPath);
    
protected:
    static SquirrelBridge *s_SquirrelBridge;
    void setupBindings(HSQUIRRELVM vm);

private:
    static void print(HSQUIRRELVM vm, const SQChar *string, ...);

};

#endif /* defined(__Massive__SquirrelBridge__) */
