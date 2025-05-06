#include "netDomain.hpp"


json getDomainRequest()
{
    return getRequest(url_api + "/getDomains");
}