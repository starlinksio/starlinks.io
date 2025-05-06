#ifndef NETTOKEN_HPP
#define NETTOKEN_HPP

#include "Requests.hpp"

json generateTokenRequest();
json getTokenHistoryRequest(const string  &token);

#endif