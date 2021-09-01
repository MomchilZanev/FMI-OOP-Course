#pragma once

class Comparable
{
public:
	virtual ~Comparable() = default;

	virtual bool operator==(const Comparable* rhs) const = 0;
	virtual bool operator!=(const Comparable* rhs) const = 0;
};