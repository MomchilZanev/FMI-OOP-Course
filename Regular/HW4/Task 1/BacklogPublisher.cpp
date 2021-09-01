#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* subscriber)
{
	SimplePublisher::subscribe(subscriber);
	for (auto message : this->messages)
	{
		this->getSubscriberById(subscriber->id)->signal(message);
	}
}

void BacklogPublisher::signal(const Message& message)
{
	SimplePublisher::signal(message);
	this->messages.push_back(message);
}

Subscriber* BacklogPublisher::getSubscriberById(const std::string& id) const
{
	for (auto subscriber : this->subscribers)
	{
		if (subscriber->id == id)
		{
			return subscriber;
		}
	}
	return nullptr;
}