#ifndef CLICK_HPP
#define CLICK_HPP

#include "entity.hpp"

struct Click
{
    Click(const string& ip, const string& country, const string& city , const string& createAt)
        : createAt(createAt), ip(ip), country(country), city(city)
    {}

    private:
        string ip;
        string country;
        string city;
        string createAt;

    public:
        string to_string() const {return "Click(ip=" + ip + ", country=" + country + ", city=" + city + ", createAt=" + createAt + ")"; }

};

#endif