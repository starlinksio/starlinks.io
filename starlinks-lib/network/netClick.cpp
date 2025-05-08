#include "netClick.hpp"



json getClicksRequests(const string& token, const string& lid, int offset)
{
    json result = getRequest(url_api + "/detailsClicksFromLink?token=" + token + "&lid=" + lid + "&offset=" + to_string(offset));

    return result;
}


json getClicksRequests(const string& token, const string& lid, const string& sid, int offset)
{
    json result = getRequest(url_api + "/detailsShortcut?token=" + token + "&lid=" + lid + "&sid=" + sid + "&offset=" + to_string(offset));

    return result;
}