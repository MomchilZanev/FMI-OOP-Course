#pragma once
#include "Object.hpp"
#include <stdexcept>

class Document : public Object
{
public:
    Document() = default;
    Document(const std::string& name, const std::string& location, const std::string& extension);

    bool operator==(const Comparable* rhs) const override;
    bool operator!=(const Comparable* rhs) const override;

    std::string to_string() const override;
    void from_string(const std::string& string) override;

    std::string debug_print() const override;

    Object* clone() const override;

    void write_line(const std::string& line);
    std::string read_line();
    std::string read_line(const unsigned& line);
private:
    void validateLine(const unsigned& line) const;

    unsigned currentLine;
    std::vector<std::string> lines;
};
