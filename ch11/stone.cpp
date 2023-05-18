#include <iostream>
#include "stonewt.hpp"

using std::cout;

void dispaly(const Stonewt &, int);

int main(int argc, char const *argv[])
{
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8 );

    cout << "The celebrity weighed ";
    incognito.show_stn();

    cout << "The detective weighed ";
    wolfe.show_stn();

    cout << "The President weighed ";
    taft.show_lbs();

    incognito = 276.8;
    taft = 325;
    
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();

    cout << "After dinner, the President weighed ";
    taft.show_stn();

    dispaly(taft, 2);
    cout << "The wrestler weighed even more.\n";

    dispaly(422, 2);
    cout << "No stone left unearned.\n";
    return 0;
}

void dispaly(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}
