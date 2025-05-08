#ifndef NETCLICK_HPP
#define NETCLICK_HPP

#include "Requests.hpp"

// return MAX 100 clicks for one request 
json getClicksRequests(const string& token, const string& lid, int offset);
json getClicksRequests(const string& token, const string& lid, const string& sid, int offset);

#endif