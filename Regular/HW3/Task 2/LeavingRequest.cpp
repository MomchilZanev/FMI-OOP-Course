#include "LeavingRequest.hpp"

LeavingRequest::LeavingRequest(const std::string& sender)
	:Request(LEAVING_MSG, sender)
{ }

const std::string LeavingRequest::LEAVING_MSG = "I want to leave!";