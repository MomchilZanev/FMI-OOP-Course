#include "Document.hpp"

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
	:Object(name, location, extension), currentLine(0)
{ }

bool Document::operator==(const Comparable* rhs) const
{
	auto rhsDocument = dynamic_cast<const Document*>(rhs);
	if (rhsDocument == nullptr)
	{
		return false;
	}
	if (this->lines.size() != rhsDocument->lines.size())
	{
		return false;
	}

	for (auto i = 0; i < this->lines.size(); i++)
	{
		if (this->lines[i] != rhsDocument->lines[i])
		{
			return false;
		}
	}
	return true;
}

bool Document::operator!=(const Comparable* rhs) const
{
	return !(*this == rhs);
}

std::string Document::to_string() const
{
	std::string result;
	
	result += Object::to_string();

	for (std::string line : this->lines)
	{
		result += line + '\n';
	}

	return result;
}

void Document::from_string(const std::string& string)
{
	std::vector<std::string> stringLines;
	Object::splitToLines(string, stringLines);
	if (stringLines.size() < 3)
	{
		return;
	}

	unsigned currentIndex = 0;
	Object::setBaseInfo(currentIndex, stringLines);

	this->lines.clear();
	for (; currentIndex < stringLines.size(); currentIndex++)
	{
		this->lines.push_back(stringLines[currentIndex]);
	}
}

std::string Document::debug_print() const
{
	std::string result;

	for (int i = 0; i < this->lines.size(); i++)
	{
		result += "Line " + std::to_string(i + 1) + ':' + this->lines[i] + '\n';
	}

	return result;
}

Object* Document::clone() const
{
	return new Document(*this);
}

void Document::write_line(const std::string& line)
{
	this->lines.push_back(line);
}

std::string Document::read_line()
{
	this->validateLine(currentLine + 1);
	return this->lines[currentLine++];
}

std::string Document::read_line(const unsigned& line)
{
	this->validateLine(line);
	this->currentLine = line - 1;
	return this->read_line();
}

void Document::validateLine(const unsigned& line) const
{
	if (line < 1 || line > this->lines.size())
	{
		throw std::out_of_range("Invalid index.");
	}
}