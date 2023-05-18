#include <iostream>
#include "tabtenn.hpp"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player_1("Tara", "Boomdea", false);
    RatedPlayer r_player_1(1140, "Mallory", "Duck", true);
    r_player_1.Name();
    if (r_player_1.hasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    
    player_1.Name();
        if (player_1.hasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    cout << "Name: ";
    r_player_1.Name();
    cout << "; Rating: " << r_player_1.Rating() << endl;

    RatedPlayer r_player_2(1212, player_1);
    cout << "Name: ";
    r_player_2.Name();
    cout << "; Rating: " << r_player_2.Rating() << endl;
    return 0;
}
