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