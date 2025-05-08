#ifndef NETLINK_HPP
#define NETLINK_HPP

#include "Requests.hpp"

bool deleteLinkRequests(const string& token, const string& id);

json createLinkRequests(const string& token, const string& url, const string& domain, const string& shortcut);

json editLInk(const string& token, const string& id, const string& new_url);

json getLinkRequest(const string& token, const string& id);
json getLinkHistoryRequest(const string& token, const string& id);

#endif