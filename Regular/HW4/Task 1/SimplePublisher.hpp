#pragma once
#include "Subscriber.hpp"

class SimplePublisher 
{
public:
	virtual void subscribe(Subscriber* subscriber);
	void unsubscribe(const Subscriber* subscriber);
	virtual void signal(const Message& message);
protected:
	bool subscriberExists(const std::string& id) const;

	std::vector<Subscriber*> subscribers;
};
