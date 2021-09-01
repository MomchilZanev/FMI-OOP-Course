#pragma once
#include "Subscriber.hpp"

class Averager : public Subscriber
{
public:
	Averager(const std::string& id);

	int read() const override;
	Subscriber* getCopy() const override;
};
