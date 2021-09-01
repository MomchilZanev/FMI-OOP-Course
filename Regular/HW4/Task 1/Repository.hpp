#pragma once
#include "Subscriber.hpp"

class Repository {
public:
	Repository() = default;
	Repository(const Repository& rhs);
	~Repository();
	Repository& operator=(const Repository& rhs);

	void add(const Subscriber* subscriber);
	Subscriber* get(const std::string& id);
private:
	void copyAllFrom(const Repository& rhs);
	void clearAll();
	std::vector<Subscriber*> subscribers;
};
