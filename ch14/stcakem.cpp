//
// Created by Tarryzking on 2023/5/22.
//
#include "iostream"
#include "string"
#include "cctype"
#include "stacktp.h"

using std::cin;
using std::cout;

int main() {
    Stack<std::string> str;
    char c;
    std::string po;
    cout << "Please enter A to add a purchase order, \n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> c && std::toupper(c) != 'Q') {
        while (cin.get() != '\n')
            continue;
        if (!std::isalpha(c)) {
            cout << '\a';
            continue;
        }
        switch (c) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (str.isfull())
                    cout << "stack already full.\n";
                else
                    str.push(po);
                break;
            case 'P':
            case 'p':
                if (str.isempty())
                    cout << "stack already empty.\n";
                else {
                    str.pop(po);
                    cout << "PO #" << po << " popped.\n";

                }
                break;
            default:
                break;
        }
        cout << "Please enter A to add a purchase order.\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Done.\n";
    return 0;
}