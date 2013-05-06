//
//  Observer.cpp
//  Massive
//
//  Created by Evan Walsh on 2/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Observer.h"

Observer *Observer::s_Observer;

Observer::Observer() {
    _paused = false;
}

Observer &Observer::GetInstance() {
    if (s_Observer == NULL) {
        s_Observer = new Observer();
    }
    
    return *s_Observer;
}

void Observer::Broadcast(Message *message) {
    _messages.push(message);
}

const bool Observer::Subscribe(Listener *listener, const String &messageName) {
    _subscriptions[listener].insert(messageName);
    std::pair<ListenerSet::iterator, bool> insertResult = _subscribers[messageName].insert(listener);
    
	return insertResult.second;
}

const bool Observer::Unsubscribe(Listener *listener, const String &messageName) {
    if (_subscribers.find(messageName) == _subscribers.end()) {
        return false;
    }
    
    ListenerSet::iterator it = _subscribers[messageName].find(listener);
    if (it == _subscribers[messageName].end()) {
        return false;
    }
    else {
        _subscribers[messageName].erase(it);
        StringSet::iterator sIt = _subscriptions[listener].find(messageName);
        if (sIt != _subscriptions[listener].end())
			_subscriptions[listener].erase(sIt);
        return true;
    }
}

const ListenerSet Observer::GetSubscribersFor(const String& messageName) {
    if (_subscribers.find(messageName) == _subscribers.end()) {
        return ListenerSet();
    }
    else {
        return _subscribers[messageName];
    }
}

const StringSet Observer::GetSubscriptionsFor(Listener *listener) {
    if (_subscriptions.find(listener) == _subscriptions.end()) {
        return StringSet();
    }
    else {
        return _subscriptions[listener];
    }
}

void Observer::SendAll() {
    while (!_messages.empty()) {
        String frontMessageName = _messages.front()->GetName();
        
        if (_subscribers.find(frontMessageName) != _subscribers.end()) {
            std::set<Listener*>::iterator listenIt = _subscribers[frontMessageName].begin();
			while (listenIt != _subscribers[frontMessageName].end()) {
				(*listenIt)->ReceiveMessage(_messages.front());
				listenIt++;
			}
        }
        
        delete _messages.front();
        _messages.pop();
    }
}