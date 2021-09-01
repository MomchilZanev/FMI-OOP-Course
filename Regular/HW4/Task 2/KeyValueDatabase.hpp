#pragma once
#include "Object.hpp"
#include <stdexcept>

class KeyValueDatabase : public Object
{
public:
	KeyValueDatabase() = default;
	KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

	bool operator==(const Comparable* rhs) const override;
	bool operator!=(const Comparable* rhs) const override;

	std::string to_string() const override;
	void from_string(const std::string& string) override;

	std::string debug_print() const override;

	Object* clone() const override;

	void add_entry(const std::pair<std::string, int>& entry);
	int get_value(const std::string& key) const;
private:
	std::string printKvp(const std::pair<std::string, int>& kvp) const;
	bool keyExists(const std::string& key) const;

	std::vector<std::pair<std::string, int>> kvpCollection;
};
