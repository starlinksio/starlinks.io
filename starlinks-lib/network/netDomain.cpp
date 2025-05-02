#include "netDomain.hpp"


json getDomainRequest()
{
    return getJsonFromUrl(url_api + "/getDomains");
}