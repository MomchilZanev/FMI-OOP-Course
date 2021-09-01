#include "Request.hpp"

Request::Request(const std::string& message, const std::string& sender)
    :message(message), sender(sender), id(++counter)
{ }

std::string Request::getMessage() const
{
    return this->message;
}

std::string Request::getSender() const
{
    return this->sender;
}

unsigned Request::getCount() const
{
    return Request::counter;
}

unsigned Request::counter;

unsigned Request::getID() const
{
    return this->id;
}