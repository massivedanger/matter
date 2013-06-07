//
//  Message.cpp
//  Massive
//
//  Created by Evan Walsh on 3/5/13.
//  Copyright (c) 2013 Massive Danger. All rights reserved.
//

#include "Message.h"
#include "Observer.h"

Message::Message() {
    _messageName = "NewMessage";
    _sender = 0;
}

const String& Message::getName() {
	return _messageName;
}

Listener* const Message::getSender() {
	return _sender;
}

Listener::~Listener() {
	StringSet subs = theObserver.getSubscriptionsFor(this);
	StringSet::iterator it = subs.begin();
	while (it != subs.end()) {
		++it;
	}
}