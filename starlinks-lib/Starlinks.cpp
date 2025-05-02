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

    cout << result.dump(4) << endl;

    if (result.is_array()) {
        for (const auto& item : result) {
            domains.emplace_back(Domain(item));
        }
    }

    return domains;
}
