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

#define theObserver Observer::getInstance()

typedef std::set<Listener *> ListenerSet;
typedef std::queue<Message *> MessageQueue; 

class Observer {
public:
    static Observer &getInstance();
    
    void broadcast(Message *message);
    const bool subscribe(Listener *listener, const String &messageName);
    const bool unsubscribe(Listener *listener, const String &messageName);
    
    const ListenerSet getSubscribersFor(const String &messageName);
    const StringSet getSubscriptionsFor(Listener *listener);
    
    void sendAll();
    
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
