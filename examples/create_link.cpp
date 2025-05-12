#include "../starlinks-lib/Starlinks.hpp"


int main()
{
    std::string token = "your_token_here"; // replace with your token

    Starlinks *s = new Starlinks(token); // connect to api

    // create link
    Link *link = s->create_link("mylinksexample.com", "myshortexample");
    if (link == nullptr) {
        std::cerr << "Failed to create link." << std::endl;
        return 1;
    }
    std::cout << "Link created:\n" << link->to_string() << std::endl;

    return 0;
}