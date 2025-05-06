#ifndef LINK_HPP
#define LINK_HPP

#include "entity.hpp"

struct Link
{
    /* data */
    Link(const string& token, const string& id, const string& createAt)
        : token(token), id(id), createAt(createAt)
    {

    }

    private:
        string token;
        string id;
        string createAt;
        string url;
        string last_click;


    public:

        void edit_link(const string& token, const string& new_url);
        void add_shortcut(const string& token, const string& shortcut);


        string get_last_click();
        string get_url();
        vector<Shortcut> get_shortcuts();

        bool delete_shortcut(const string& token, const string& id);

        string get_id() const { return id; }
        string to_string() const {return "Link(id=" + id + ", createAt=" + createAt + ")"; }
};

#endif
