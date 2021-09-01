#pragma once
#include "Helpers.hpp"
#include "Averager.hpp"

class MovingAverager : public Averager
{
public:
	MovingAverager(const std::string& id, const size_t& windowSize);

	void signal(const Message& message) override;
	Subscriber* getCopy() const override;

	const size_t windowSize;
private:
	void copyLastXElements(const std::vector<Message>& source, std::vector<Message>& destination, const size_t& x) const;
	void refillContainer(const std::vector<Message>& source, std::vector<Message>& destination);
};
