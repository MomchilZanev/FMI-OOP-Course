#include "Repository.hpp"

Repository::Repository(const Repository& rhs)
{
	this->copyAllFrom(rhs);
}

Repository::~Repository()
{
	this->clearAll();
}

Repository& Repository::operator=(const Repository& rhs)
{
	if (this != &rhs)
	{
		this->clearAll();
		this->copyAllFrom(rhs);
	}
	return *this;
}

void Repository::add(const Subscriber* subscriber)
{
	this->subscribers.push_back(subscriber->getCopy());
}

Subscriber* Repository::get(const std::string& id)
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

void Repository::copyAllFrom(const Repository& rhs)
{
	for (auto subscriber : rhs.subscribers)
	{
		this->add(subscriber);
	}
}

void Repository::clearAll()
{
	for (auto subscriber : this->subscribers)
	{
		delete subscriber;
	}
	this->subscribers.clear();
}