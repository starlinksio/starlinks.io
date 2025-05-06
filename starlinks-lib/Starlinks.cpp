#include "Starlinks.hpp"


Starlinks::Starlinks()
{
    token = new Token();
}

Starlinks::Starlinks(const string& t)
{
    token = new Token(t);
}

Starlinks::~Starlinks(){}


vector<Domain> Starlinks::get_domains()
{
    vector<Domain> domains;

    json result = getDomainRequest();


    if (result.is_array()) {
        for (const auto& item : result) {
            if (!item.empty() && item.contains("domain")) {
                domains.emplace_back(Domain(item));
            }
        }
    }

    return domains;
}


vector<Link> Starlinks::get_links()
{
    vector<Link> links;
    token->getHistory();

    links = token->get_links();

    return links;
}


bool Starlinks::delete_link(const string& id)
{
    return deleteLinkRequests(token->token,id);
}

bool Starlinks::delete_shorcut(const string& id)
{
    return deleteShortcutRequests(token->token,id);
}




vector<Shortcut> Starlinks::get_shortcuts(Link *link)
{

}
vector<Shortcut> Starlinks::get_shortcuts(const string& link_id)
{
    vector<Shortcut> shorts;

    json result = getLinkHistoryRequest(token->token, link_id);

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