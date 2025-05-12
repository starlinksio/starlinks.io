#include "../starlinks-lib/Starlinks.hpp"


int main()
{
    std::string token = "your_token_here"; // replace with your token

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
    Link link = links[0];

    // get shortcuts
    vector<Shortcut> shorts = link.get_shortcuts();
    std::cout << "Shortcuts size: " << shorts.size() << std::endl;

    //add shortcut
    link.add_shortcut("domain-name", "my-shortcut");
    std::cout << "Shortcut added:\n" << link.to_string() << std::endl;
    
    // get shortcuts
    vector<Shortcut> shorts = link.get_shortcuts();
    std::cout << "Shortcuts size: " << shorts.size() << std::endl;

    return 0;
}