#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string& id, const size_t& windowSize)
	:Averager(id), windowSize(windowSize)
{ }

void MovingAverager::signal(const Message& message)
{
	if (this->messages.size() >= this->windowSize)
	{
		std::vector<Message> newContainer;
		this->copyLastXElements(this->messages, newContainer, this->windowSize - 1);
		this->refillContainer(newContainer, this->messages);
	}
	Subscriber::signal(message);
}

Subscriber* MovingAverager::getCopy() const
{
	return new MovingAverager(*this);
}

void MovingAverager::copyLastXElements(const std::vector<Message>& source, std::vector<Message>& destination, const size_t& x) const
{
	const size_t startIndex = getMax<size_t>(source.size() - x, 0);
	const size_t endIndex = source.size() - 1;
	for (size_t i = startIndex; i <= endIndex; i++)
	{
		destination.push_back(source[i]);
	}
}

void MovingAverager::refillContainer(const std::vector<Message>& source, std::vector<Message>& destination)
{
	destination.clear();
	for (auto message : source)
	{
		destination.push_back(message);
	}
}