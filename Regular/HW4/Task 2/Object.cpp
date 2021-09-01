#include "Object.hpp"

Object::Object(const std::string& name, const std::string& location, const std::string& extension)
	:name(name), location(location), extension(extension)
{ }

std::string Object::to_string() const
{
	std::string result;

	result += this->get_name() + '\n';
	result += this->get_location() + '\n';
	result += this->get_extension() + '\n';

	return result;
}

std::string Object::get_name() const
{
	return this->name;
}

std::string Object::get_location() const
{
	return this->location;
}

std::string Object::get_extension() const
{
	return this->extension;
}

std::string Object::get_fullpath() const
{
	return this->location + '/' + this->name + '.' + this->extension;
}

void Object::splitToLines(const std::string& string, std::vector<std::string>& container) const
{
	std::stringstream ss(string);
	std::string line;

	if (string != "")
	{
		while (std::getline(ss, line, '\n'))
		{
			container.push_back(line);
		}
	}
}

void Object::setBaseInfo(unsigned& index, const std::vector<std::string>& container)
{
	this->name = container[index++];
	this->location = container[index++];
	this->extension = container[index++];
}