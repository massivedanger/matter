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

class Listener;

class Message {
    
public:
    Message();
    Message(const String& messageName, Listener *sender = NULL);
    
    virtual const String& GetName();
    Listener* const GetSender();
    
protected:
    String _messageName;
    Listener *_sender;
};

class Listener {
    
public:
    virtual ~Listener();
    
    virtual void ReceiveMessage(Message *message) = 0;
};

#endif /* defined(__Massive__Message__) */
