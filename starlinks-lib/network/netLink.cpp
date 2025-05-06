#include "netLink.hpp"

bool deleteLinkRequests(const string& token, const string& id)
{
    json result = deleteRequest(url_api + "/deleteEntity?token=" + token + "&type=Link&id=" + id);

    if(result.contains("error")){
        cout << result["message"].get<string>() << endl;
        return false;
    }

    return true;
}

json getLinkHistoryRequest(const string& token, const string& id)
{
    json result = getRequest(url_api + "/detailsLink?token=" + token + "&lid=" + id );

    return result;
}