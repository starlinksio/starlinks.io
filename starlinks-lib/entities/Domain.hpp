#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Domain
{
    string domain;
    bool isDefault;

    Domain(json value)
    {
        domain = value["domain"].get<string>();
        isDefault = value["default"].get<bool>();
    }

    string to_string() const {return "Domain(domain=" + domain + " ,isDefault=" + ( isDefault ? "true" : "false") + ")"; }

};
