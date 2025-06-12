#include "Link.hpp"


string Link::get_last_click()
{
    json result = getLinkRequest(token, id);

    if(result.contains("error")){
        return result["message"].get<string>();
    }

    return result["lastClick"].get<string>();
}

string Link::get_url()
{
    json result = getLinkRequest(token, id);

    if(result.contains("error")){
        return result["message"].get<string>();
    }

    return result["url"].get<string>();
}

vector<Shortcut> Link::get_shortcuts()
{
    vector<Shortcut> shorts;

    json result = getLinkHistoryRequest(token, id);

    if(result.contains("error")){
        cout << result["message"].get<string>() << endl;
        return shorts;
    }

    if (result.is_array()) {
        for (const auto& item : result) {
            if (!item.empty() && item.contains("type") && item["type"] == "Shortcut") {
                shorts.emplace_back(Shortcut(item, token, id));
            }
        }
    }

    return shorts;
}

void Link::edit_link(const string& new_url)
{
    json result = editLInk(token, id, new_url);

    cout << result.dump(4) << endl;
}

bool Link::add_shortcut(const string& domain, const string& shortcut)
{
    json result = addShrotcut(token, id, domain, shortcut);

    cout << result.dump(4) << endl;

    return result.contains("status") && result["status"] == "success";
}

vector<Click> Link::get_clicks(int offset)
{
    vector<Click> clicks;
    
    json result = getClicksRequests(token, id , offset);


    if(result.contains("error")){
        cout << result["message"].get<string>() << endl;
        return clicks;
    }

    if (result.is_array()) {
        for (const auto& item : result) {
            if (!item.empty() && item.contains("type") && item["type"] == "Click") {
                clicks.emplace_back(Click(item["ip"],item["country"],item["city"],item["createAt"]));
            }
        }
    }
    return clicks;

}


bool Link::delete_shortcut(const string& id)
{
    return deleteShortcutRequests(token,id);
}