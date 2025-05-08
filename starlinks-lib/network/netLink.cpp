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


json editLInk(const string& token, const string& id, const string& new_url)
{
    json payload;

    payload["token"] = token;
    payload["lid"] = id;
    payload["newUrl"] = new_url;

    json result = postRequest(url_api + "/editLink",payload);

    return result;
}


json getLinkRequest(const string& token, const string& id)
{
    json result = getRequest(url_api + "/getLink?token=" + token + "&lid=" + id );

    return result;
}

json getLinkHistoryRequest(const string& token, const string& id)
{
    json result = getRequest(url_api + "/detailsLink?token=" + token + "&lid=" + id );

    return result;
}


json createLinkRequests(const string& token, const string& url, const string& domain, const string& shortcut)
{
    json result = getRequest(url_api + "/createShortcutUrl?token=" + token + "&url=" + url + "&domain=" + domain + "&shortcut=" + shortcut );

    return result;
}


