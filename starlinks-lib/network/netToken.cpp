#include "netToken.hpp"


json generateTokenRequest()
{
    return getRequest(url_api + "/generateToken"); 
}

json getTokenHistoryRequest(const string  &token)
{
    return getRequest(url_api + "/details?token=" + token); 
}