#include <iostream>
#include "dma.hpp"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercatoe", "Buffalo", 5);

    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;

    lacksDMA balloon_2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon_2 << endl;

    hasDMA map_2;
    map_2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map_2 << endl;
    return 0;
}
