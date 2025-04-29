#ifndef STARLINKS_HPP
#define STARLINKS_HPP

#include "entities/Token.hpp"
#include "entities/Link.hpp"
#include "entities/Shortcut.hpp"
#include "entities/Click.hpp"
#include "entities/Domain.hpp"

#include <iostream>
#include <string>
#include <vector>

class Starlinks
{
    private:
        /* data */
        Token token;
        

    public:
        Starlinks(/* args */);
        ~Starlinks();

        Link* create_link();
        Shortcut* add_shortcut();

        bool delete_link();
        bool delete_shorcut();

        string get_token() { return token.token; }
        
        vector<Domain> get_domains();

        vector<Link> get_links();
        vector<Shortcut> get_shortcuts(Link *link);
        vector<Click> get_clicks();



};

Starlinks::Starlinks(/* args */)
{
}

Starlinks::~Starlinks()
{
}



#endif