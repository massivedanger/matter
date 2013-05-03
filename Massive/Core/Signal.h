//
//  Signal.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#pragma once

#ifndef __Massive__Signal__
#define __Massive__Signal__

#include <queue>
#include <string>
#include <set>
#include "Message.h"

class Signal {
public:
    static Signal& GetInstance();
    void Update(float dt);
    
    bool Subscribe(Message *message);
    bool Unsubscribe(Listener *listener, const std::string& messageType);
    bool Broadcast(Message *message);
    
    const std::set<Listener *> GetSubscribersFor(const std::string& messageType);
    const std::set<std::string *> GetSubscriptionsFor(Listener *listener);
    
    void SendAll();
    
protected:
    Signal();
    static Signal *s_signal;
    
private:
    std::queue<Message *> _messages;
    ~Signal();
};

#endif /* defined(__Massive__Signal__) */
