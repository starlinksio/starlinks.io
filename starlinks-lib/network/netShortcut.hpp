#ifndef NETSHORTCUT_HPP
#define NETSHORTCUT_HPP

#include "Requests.hpp"

json addShrotcut(const string& token, const string& lid,  const string& domain, const string& shortcut);

bool deleteShortcutRequests(const string& token, const string& id);

#endif