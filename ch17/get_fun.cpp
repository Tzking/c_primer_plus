//
// Created by Tarryzking on 2023/6/2.
//
#include "iostream"

const int Limit = 255;

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    char input[Limit];

    cout << "Enter a string for getline() processing:\n";
    cin.getline(input, Limit, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 1\n";

    char c;
    cin.get(c);
    cout << "The next input character is " << c << endl;

    if (c != '\n')
        cin.ignore(Limit, '\n');

    cout << "Enter a string for get() processing:\n";
    cin.get(input, Limit, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 2";

    cin.get(c);
    cout << "The next input character is " << c << endl;
    return 0;
}