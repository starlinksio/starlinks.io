#include "starlinks-lib/Starlinks.hpp"


int main()
{

    Starlinks *s = new Starlinks(); // create token

    s->create_link("mylinksexample.com", "myshortexample");

    vector<Link> links = s->get_links();

    cout << "Links: " << links.size() << endl;
 
    for(Link l : links){
        cout << l.to_string() << endl;
        vector<Shortcut> shorts = l.get_shortcuts();

        for(Shortcut s : shorts)
        {
            
            vector<Click> clicks = s.get_clicks(0);
            cout << s.to_string() << " Clicks: " << clicks.size() << endl;
            for(Click c : clicks)
            {
                cout << c.to_string() << endl;
            }
        }
    }

    return 0;
}