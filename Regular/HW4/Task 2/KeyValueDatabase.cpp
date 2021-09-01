#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension)
	:Object(name, location, extension)
{ }

bool KeyValueDatabase::operator==(const Comparable* rhs) const
{
	auto rhsKvpDb = dynamic_cast<const KeyValueDatabase*>(rhs);
	if (rhsKvpDb == nullptr)
	{
		return false;
	}
	if (this->kvpCollection.size() != rhsKvpDb->kvpCollection.size())
	{
		return false;
	}

	for (auto kvp : this->kvpCollection)
	{
		int rhsValue;
		try
		{
			rhsValue = rhsKvpDb->get_value(kvp.first);
		}
		catch (const std::invalid_argument& ex)
		{
			return false;
		}
		if (kvp.second != rhsValue)
		{
			return false;
		}
	}
	return true;
}

bool KeyValueDatabase::operator!=(const Comparable* rhs) const
{
	return !(*this == rhs);
}

std::string KeyValueDatabase::to_string() const
{
	std::string result;

	result += Object::to_string();

	for (auto kvp : this->kvpCollection)
	{
		result += this->printKvp(kvp) + '\n';
	}

	return result;
}

void KeyValueDatabase::from_string(const std::string& string)
{
	std::vector<std::string> stringLines;
	Object::splitToLines(string, stringLines);
	if (stringLines.size() < 3)
	{
		return;
	}

	unsigned currentIndex = 0;
	Object::setBaseInfo(currentIndex, stringLines);

	this->kvpCollection.clear();
	for (; currentIndex < stringLines.size(); currentIndex++)
	{
		std::stringstream ss(stringLines[currentIndex]);
		std::string kvpElem;
		std::vector<std::string> kvp;
		while (std::getline(ss, kvpElem, ':'))
		{
			kvp.push_back(kvpElem);
		}
		std::pair<std::string, int> newKvp(kvp[0], std::stoi(kvp[1]));
		this->kvpCollection.push_back(newKvp);
	}
}

std::string KeyValueDatabase::debug_print() const
{
	std::string result;

	for (auto kvp : this->kvpCollection)
	{
		result += '{' + this->printKvp(kvp) + '}' + '\n';
	}

	return result;
}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	if (this->keyExists(entry.first))
	{
		throw std::invalid_argument("Key already exists.");
	}
	this->kvpCollection.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	if (!this->keyExists(key))
	{
		throw std::invalid_argument("Key doesn't exist in database");
	}

	for (auto kvp : this->kvpCollection)
	{
		if (kvp.first == key)
		{
			return kvp.second;
		}
	}
}

std::string KeyValueDatabase::printKvp(const std::pair<std::string, int>& kvp) const
{
	return kvp.first + ':' + std::to_string(kvp.second);
}

bool KeyValueDatabase::keyExists(const std::string& key) const
{
	for (auto kvp : this->kvpCollection)
	{
		if (kvp.first == key)
		{
			return true;
		}
	}
	return false;
}