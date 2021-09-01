#pragma once
#include "Request.hpp"

class LeavingRequest : public Request
{
public:
	static const std::string LEAVING_MSG;

	LeavingRequest(const std::string& sender);
};