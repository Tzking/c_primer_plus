//
// Created by Tarryzking on 2023/5/31.
//
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

void output(const std::string &s) {
    std::cout << s << " ";
}

int main() {
    using namespace std;
    string s_1[4] = {"fine", "fish", "fashion", "fate"};
    string s_2[2] = {"busy", "bats"};
    string s_3[2] = {"silly", "singers"};

    vector<string> words(4);
    copy(s_1, s_1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    copy(s_2, s_2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    copy(s_3, s_3 + 2, insert_iterator<vector<string>>(words, words.begin()));
    for_each(words.begin(), words.end(), output);
    cout << endl;
    return 0;
}