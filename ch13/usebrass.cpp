#include <iostream>
#include <string>
#include "brass.hpp"

const int CLIENTS = 4;

int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass * p_clients[CLIENTS];
    std::string temp;
    long num;
    double balance;
    char kind;
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> num;
        cout << "Enter opening balance : $";
        cin >> balance;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";

        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, num, balance);
        else
        {
            double max, rate;
            cout << "Enter the overdraft limit: $";
            cin >> max;
            cout << "Enter the interest rate "
                << "as a decimal fraction: ";
            cin >> rate;
            p_clients[i] = new Brass_plus(temp, num, balance, max, rate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;

    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->Viewaccount();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout << "Done.\n";
    return 0;
}
