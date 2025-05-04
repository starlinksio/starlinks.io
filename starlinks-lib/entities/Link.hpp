#ifndef LINK_HPP
#define LINK_HPP

#include "entity.hpp"

struct Link
{
    /* data */
    Link(const string& id, const string& createAt)
        : id(id), createAt(createAt)
    {

    }

    private:
        string id;
        string createAt;
        string url;
        string last_click;

    public:
        string get_last_click();
        string get_url();
        vector<Shortcut> get_shortcuts();
};

#endif
