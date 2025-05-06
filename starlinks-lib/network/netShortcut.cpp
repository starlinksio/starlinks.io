#include "netShortcut.hpp"

bool deleteShortcutRequests(const string& token, const string& id)
{
    json result = deleteRequest(url_api + "/deleteEntity?token=" + token + "&type=Shortcut&id=" + id);

    if(result.contains("error")){
        cout << result["message"].get<string>() << endl;
        return false;
    }

    return true;
}