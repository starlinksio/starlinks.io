#include "../starlinks-lib/Starlinks.hpp"


int main()
{
    std::string token = "your_token_here"; // replace with your token
    std::string newUrl = "your_new_url_here"; // replace with new url 

    Starlinks *s = new Starlinks(token); // connect to api

    // get links
    vector<Link> links = s->get_links();
    
    // needt to choose a link
    // for example we will use the first link
    if(links.size() == 0)
    {
        std::cerr << "No links found." << std::endl;
        return 1;
    }


    /*
        You need to choose the correct link to edit 
    */
    links[0].edit_link(newUrl);

    return 0;
}