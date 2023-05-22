#include <iostream>
#include "worker.hpp"

const int Limit = 4;

int main(int argc, char const *argv[])
{
    Waitor bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waitor w_t;
    Singer s_t;

    Worker * pw[Limit] = {&bob, &bev, &w_t, &s_t};
    int i;
    for ( i = 2; i < Limit; i++)
        pw[i]->set();
    for (i = 0; i < Limit; i++)
    {
        pw[i]->show();
        std::cout << std::endl;
    }
    
    return 0;
}
