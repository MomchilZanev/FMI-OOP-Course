#pragma once
#include "Message.hpp"
#include <string>
#include <vector>

class Subscriber
{
public:
	Subscriber(const std::string& id);
	virtual ~Subscriber() = default;

	virtual void signal(const Message& message);
	virtual int read() const = 0;
	virtual Subscriber* getCopy() const = 0;

	const std::string id;
protected:
	static const int EMPTY_DEF = 0;
	std::vector<Message> messages;
};