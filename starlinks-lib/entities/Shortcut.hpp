#ifndef SHORTCUT_HPP
#define SHORTCUT_HPP

#include "entity.hpp"

struct Shortcut
{
    /* data */

    Shortcut(const string& id, const string& shortcut, const string &createAt) 
    : id(id), shortcut(shortcut), createAt(createAt)
    {

    }

    public:
        string to_string() const {return "Shortcut(id=" + id + ", shortcut=" + shortcut + ", createAt=" + createAt + ")"; }


    private:
        string id; 
        string shortcut; 
        string createAt;

};

#endif
