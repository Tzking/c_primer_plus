//
// Created by Tarryzking on 2023/6/2.
//
#include "iostream"

const int Len = 10;

inline void eatline() { while (std::cin.get() != '\n') continue; }

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    char name[Len];
    char title[Len];
    cout << "Enter your name: ";
    cin.get(name, Len);
    if (cin.peek() != '\n')
        cout << "Sorry, we only have enough room for "
             << name << endl;
    eatline();
    cout << "Dear " << name << ", enter your title:\n";
    cin.get(title, Len);
    if (cin.peek() != '\n')
        cout << "We were forced to truncate your title.\n";
    eatline();
    cout << " Name: " << name
         << "\nTitle: " << title << endl;
    return 0;
}