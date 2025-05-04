

#include <iostream>
#include <string>

#include "../network/netToken.hpp"


using namespace std;

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
        void generateToken();

};
