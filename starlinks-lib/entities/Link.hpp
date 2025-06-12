#ifndef LINK_HPP
#define LINK_HPP

#include "entity.hpp"

struct Shortcut;

struct Link
{
    /* data */
    Link(const string& token, const string& id, const string& createAt, const string& url, const string& last_click)
        : token(token), id(id), createAt(createAt), url(url), last_click(last_click)
    {}

    Link(const string& token,const json item) : token(token)
    {
        if(item.contains("type") && item["type"] == "Link"){
            id = item["id"].get<string>();
        }else{
            id = item["linkId"].get<string>();
        }

        createAt = item["createAt"].get<string>();

        if(item.contains("type") && item["type"] == "Link"){
            url = item["url"].get<string>();
        }else{
            url = item["nextUrl"].get<string>();
        }

        last_click = "";
    }

    private:
        string token;
        string id;
        string createAt;
        string url;
        string last_click;


    public:

        void edit_link(const string& new_url);
        bool add_shortcut(const string& domain, const string& shortcut); // true if success, false if error


        string get_last_click();
        string get_url();
        vector<Shortcut> get_shortcuts();

        vector<Click> get_clicks(int offset); 

        bool delete_shortcut(const string& id);

        string get_id() const { return id; }
        string to_string() const {return "Link(id=" + id + ", url=" + url + ", createAt=" + createAt + ")"; }
};

#endif
