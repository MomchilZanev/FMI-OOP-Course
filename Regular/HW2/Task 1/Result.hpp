#pragma once
#include "Error.hpp"
#include "Optional.hpp"

template<typename T>
class Result
{
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    bool operator==(const T& rhs) const;
    bool operator==(const Error& rhs) const;

    Optional<T> get_result() const;
    Optional<Error> get_error() const;
private:
    Optional<T> result;
    Optional<Error> error;
};

template<typename T>
Result<T>::Result() : result(Optional<T>()), error(Optional<Error>())
{ }

template<typename T>
Result<T>::Result(const T& result) : result(Optional<T>(result)), error(Optional<Error>())
{ }

template<typename T>
Result<T>::Result(const std::string& error_message) : result(Optional<T>()), error(Optional<Error>(Error(error_message)))
{ }

template<typename T>
bool Result<T>::operator==(const T& rhs) const
{
    return !this->result.is_none() && this->error.is_none();
}

template<typename T>
bool Result<T>::operator==(const Error& rhs) const
{
    return this->result.is_none() && !this->error.is_none();
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
    return this->result;
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
    return this->error;
}