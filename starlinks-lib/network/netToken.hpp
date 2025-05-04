#ifndef NETTOKEN_HPP
#define NETTOKEN_HPP

#include "Requests.hpp"

json generateTokenRequest();
json getHistoryRequest(const string  &token);
#endif