#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "entity.hpp"


struct Link;

struct Token
{
    Token()
    {
        generateToken();
    }
    
    Token(const string& token): token(token)
    {

    }
    /* data */
    string token;

    private:
        vector<Link> links;

        void generateToken();

    public:
        void getHistory();

        vector<Link> get_links(){ return links; }


};


#endif