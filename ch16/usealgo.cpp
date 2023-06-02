//
// Created by Tarryzking on 2023/6/1.
//
#include "iostream"
#include "string"
#include "vector"
#include "set"
#include "map"
#include "algorithm"
#include "cctype"

using namespace std;

char ToLower(char c) { return tolower(c); }

string &toLower(string &str);

void display(const string &s);

int main() {
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while (cin >> input && input != "quit") {
        words.push_back(input);
    }

    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;

    set<string> word_set;
    transform(words.begin(), words.end(), insert_iterator<set<string>>(word_set, word_set.begin()), toLower);
    cout << "\nAlphabetic list of words:\n";
    for_each(word_set.begin(), word_set.end(), display);
    cout << endl;

    map<string, int> word_map;
    set<string>::iterator it;
    for (it = word_set.begin(); it != word_set.end(); ++it) {
        word_map[*it] = count(words.begin(), words.end(), *it);
    }

    cout << "Word frequency:\n";
    for (it = word_set.begin(); it != word_set.end(); ++it) {
        cout << *it << ": " << word_map[*it] << endl;
    }
    return 0;
}

string &toLower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ToLower);
    return str;
}

void display(const string &s) {
    cout << s << " ";
}
