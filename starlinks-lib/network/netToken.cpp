#include "netToken.hpp"


json generateTokenRequest()
{
    return getJsonFromUrl(url_api + "/generateToken"); 
}