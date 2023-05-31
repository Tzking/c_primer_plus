//
// Created by Tarryzking on 2023/5/29.
//
#include "iostream"
#include "string"
#include "vector"

const int NUM = 5;

int main() {
    using std::vector;
    using std::cout;
    using std::cin;
    using std::string;

    vector<int> ratings(NUM);
    vector<string> titles(NUM);

    cout << "You will do exactly as told. You will enter\n"
         << NUM << " book titles and your ratings (0-10).\n";

    for (int i = 0; i < NUM; ++i) {
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter you rating (0-10): ";
        cin >> ratings[i];
        cin.get();
    }
    cout << "Thank you. You entered the following:\n"
         << "Rating\tBook\n";
    for (int i = 0; i < NUM; ++i) {
        cout << ratings[i] << "\t" << titles[i] << std::endl;
    }
    return 0;
}