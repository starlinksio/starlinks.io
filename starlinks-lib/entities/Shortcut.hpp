#ifndef SHORTCUT_HPP
#define SHORTCUT_HPP

#include "entity.hpp"


struct Click;

struct Shortcut
{
    /* data */

    Shortcut(
                const json item, 
                const string& token, 
                const string& lid) 
        : token(token), lid(lid)
    {
        id = item["id"].get<string>();
        shortcut = item["shortcut"].get<string>();
        createAt = item["createAt"].get<string>();
    }

    Shortcut(){}

    public:
        vector<Click> get_clicks(int offset); 
        string to_string() const {return "Shortcut(id=" + id + ", shortcut=" + shortcut + ", createAt=" + createAt + ")"; }


    private:
        string id; 
        string token;
        string lid; // link ID
        string shortcut; 
        string createAt;

};

#endif
