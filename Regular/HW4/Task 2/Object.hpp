#pragma once
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"
#include <vector>
#include <sstream>

class Object : public Comparable, public Debug, public Serializable
{
public:
    Object() = default;
    Object(const std::string& name, const std::string& location, const std::string& extension);
    virtual ~Object() = default;

    std::string to_string() const override;

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;
    virtual Object* clone() const = 0;
protected:
    void splitToLines(const std::string& string, std::vector<std::string>& container) const;
    void setBaseInfo(unsigned& index, const std::vector<std::string>& container);

    std::string name;
    std::string location;
    std::string extension;
};