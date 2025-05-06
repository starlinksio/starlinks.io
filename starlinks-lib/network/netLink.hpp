#ifndef NETLINK_HPP
#define NETLINK_HPP

#include "Requests.hpp"

bool deleteLinkRequests(const string& token, const string& id);
json getLinkHistoryRequest(const string& token, const string& id);

#endif