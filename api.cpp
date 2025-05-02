#include "starlinks-lib/Starlinks.hpp"


int main()
{
    Starlinks *s = new Starlinks();

    vector<Domain> domains = s->get_domains();

    for (Domain d : domains)
    {
        cout << d.to_string() << endl;
    }

    return 0;
}