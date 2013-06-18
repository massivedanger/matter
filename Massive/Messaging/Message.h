//
//  Message.h
//  Massive
//
//  Created by Evan Walsh on 3/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#ifndef __Massive__Message__
#define __Massive__Message__

#include "../Utilities/Common.h"

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/filestream.h>

class Listener;

class Message {
    
public:
    Message();
    Message(const String& messageName, Listener *sender = NULL);
    Listener* const getSender();
    
    String name;
    String json;
    
    rapidjson::Document getParsedJSON();
    
protected:
    Listener *_sender;
};

class Listener {
    
public:
    virtual ~Listener();
    virtual void receiveMessage(Message *message) {};
};

#endif /* defined(__Massive__Message__) */
