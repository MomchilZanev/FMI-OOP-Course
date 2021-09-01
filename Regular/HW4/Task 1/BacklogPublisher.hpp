#pragma once
#include "SimplePublisher.hpp"

class BacklogPublisher : public SimplePublisher
{
public:
	void subscribe(Subscriber* subscriber) override;
	void signal(const Message& message) override;
private:
	Subscriber* getSubscriberById(const std::string& id) const;

	std::vector<Message> messages;
};
