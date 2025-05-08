#include "Shortcut.hpp"


vector<Click> Shortcut::get_clicks(int offset)
{
    vector<Click> clicks;
    
    json result = getClicksRequests(token, lid, id , offset);


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