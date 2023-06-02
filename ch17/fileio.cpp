//
// Created by Tarryzking on 2023/6/2.
//
#include "iostream"
#include "fstream"
#include "string"

int main() {
    using namespace std;
    string file_name;

    cout << "Enter name for new file: ";
    cin >> file_name;

    ofstream f_out(file_name.c_str());

    f_out << "For your eyes only.\n";
    cout << "Enter your secret number: ";
    float secret;
    cin >> secret;

    f_out << "Your secret number is " << secret << endl;
    f_out.close();

    ifstream f_in(file_name.c_str());
    cout << "Here are the contents of " << file_name << ":\n";
    char c;
    while (f_in.get(c)) {
        cout << c;
    }
    cout << "Done.\n";
    f_in.close();
    return 0;
}