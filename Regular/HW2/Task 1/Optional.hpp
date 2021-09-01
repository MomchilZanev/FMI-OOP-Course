#pragma once

template <typename T>
class Optional 
{
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;
private:
    bool none;
    T value;
};

template<typename T>
Optional<T>::Optional()
{
    this->value = T();
    this->none = true;
}

template<typename T>
Optional<T>::Optional(const T& value)
{
    this->value = value;
    this->none = false;
}

template<typename T>
bool Optional<T>::is_none() const
{
    return this->none;
}

template<typename T>
T Optional<T>::get_value() const
{
    return this->value;
}