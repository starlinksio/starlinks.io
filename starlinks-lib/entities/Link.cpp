#include "Link.hpp"


string Link::get_last_click()
{

}

string Link::get_url()
{

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
                shorts.emplace_back(Shortcut(item["id"],item["shortcut"],item["createAt"]));
            }
        }
    }

    return shorts;
}

void Link::edit_link(const string& token, const string& new_url)
{

}