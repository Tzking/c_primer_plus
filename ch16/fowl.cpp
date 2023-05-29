//
// Created by Tarryzking on 2023/5/29.
//
#include <memory>

#include "iostream"
#include "string"
#include "memory"

int main() {
    using namespace std;
    shared_ptr<string> films[5] = {
            std::make_shared<string> ("Fowl Balls"),
            std::make_shared<string> ("Duck Walks"),
            std::make_shared<string> ("Chicken Runs"),
            std::make_shared<string> ("Turkey Error"),
            std::make_shared<string> ("Goose Eggs")
    };
    shared_ptr<string> p_win;
    p_win = films[2];

    cout << "The nominees for best avian baseball film are\n";
    for (const auto & film : films) {
        cout << *film << endl;
    }
    cout << "The winner is " << *p_win << ".\n";
    cin.get();
    return 0;
}