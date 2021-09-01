#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber* subscriber)
{
	if (!this->subscriberExists(subscriber->id))
	{
		this->subscribers.push_back(subscriber);
	}	
}

void SimplePublisher::unsubscribe(const Subscriber* subscriber)
{
	for (auto i = 0; i < this->subscribers.size(); i++)
	{
		if (this->subscribers[i]->id == subscriber->id)
		{
			this->subscribers.erase(this->subscribers.begin() + i);
			return;
		}
	}
}

void SimplePublisher::signal(const Message& message)
{
	for (auto subscriber : this->subscribers)
	{
		subscriber->signal(message);
	}
}

bool SimplePublisher::subscriberExists(const std::string& id) const
{
	for (auto subscriber : this->subscribers)
	{
		if (subscriber->id == id)
		{
			return true;
		}
	}
	return false;
}