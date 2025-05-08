#include "netShortcut.hpp"



json addShrotcut(const string& token, const string& lid,  const string& domain, const string& shortcut)
{
    json payload;
    payload["token"] = token;
    payload["lid"] = lid;
    payload["domain"] = domain;
    payload["shortcut"] = shortcut;

    json result = postRequest(url_api + "/addShortLink",payload);

    return result;
}


bool deleteShortcutRequests(const string& token, const string& id)
{
    json result = deleteRequest(url_api + "/deleteEntity?token=" + token + "&type=Shortcut&id=" + id);

    if(result.contains("error")){
        cout << result["message"].get<string>() << endl;
        return false;
    }

    return true;
}