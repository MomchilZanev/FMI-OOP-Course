#include "Averager.hpp"

Averager::Averager(const std::string& id)
	:Subscriber(id)
{ }

int Averager::read() const
{
	int messagesCount = this->messages.size();
	int dataTotal = 0;
	for (auto message : this->messages)
	{
		dataTotal += message.data;
	}
	return this->messages.empty() ? EMPTY_DEF : dataTotal / messagesCount;
}

Subscriber* Averager::getCopy() const
{
	return new Averager(*this);
}