#include "Subscriber.hpp"

Subscriber::Subscriber(const std::string& id)
	: id(id)
{ }

void Subscriber::signal(const Message& message)
{
	this->messages.push_back(message);
}