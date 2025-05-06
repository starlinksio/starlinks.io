#ifndef CLICK_HPP
#define CLICK_HPP

#include "entity.hpp"

struct Click
{
    Click()
    {}

    private:
        string id;
        string createAt;
        string ip;
        string country;
        string city;
};

#endif