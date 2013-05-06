//
//  Observer.h
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#pragma once

#ifndef __Massive__Observer__
#define __Massive__Observer__

#include <queue>
#include "../Utilities/Common.h"
#include "Message.h"

#define theObserver Observer::GetInstance()

typedef std::set<Listener *> ListenerSet;
typedef std::queue<Message *> MessageQueue; 

class Observer {
public:
    static Observer &GetInstance();
    
    void Broadcast(Message *message);
    const bool Subscribe(Listener *listener, const String &messageName);
    const bool Unsubscribe(Listener *listener, const String &messageName);
    
    const ListenerSet GetSubscribersFor(const String &messageName);
    const StringSet GetSubscriptionsFor(Listener *listener);
    
    void SendAll();
    
protected:
    Observer();
    static Observer *s_Observer;
    
private:
    MessageQueue _messages;
    std::map<Listener *, StringSet> _subscriptions;
    std::map<String, ListenerSet> _subscribers;
    bool _paused;
    ~Observer();
};

#endif /* defined(__Massive__Observer__) */
