#ifndef STARLINKS_HPP
#define STARLINKS_HPP

#include "entities/entity.hpp"


class Starlinks
{
    private:
        /* data */
        Token *token;
        

    public:
        Starlinks();
        Starlinks(const string& t);
        ~Starlinks();

        Link* create_link(const string& url, const string& shortcut);
        Link* create_link(const string& url, const string& domain, const string& shortcut);

        bool delete_link(const string& id);
        bool delete_shorcut(const string& id);

        string get_token() { return token->token; }
        
        vector<Domain> get_domains();

        vector<Link> get_links();
        vector<Shortcut> get_shortcuts(Link *link);
        vector<Shortcut> get_shortcuts(const string& link_id);

};





#endif