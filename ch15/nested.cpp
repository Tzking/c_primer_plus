//
// Created by Tarryzking on 2023/5/28.
//
#include "iostream"
#include "string"
#include "queuetp.h"

int main() {
    using std::cout;
    using std::cin;
    using std::string;

    Queue<string> str(5);
    string temp;

    while (!str.isfull()) {
        cout << "Please enter you name. You will be "
                "served in the order of arrival.\n"
                "name: ";
        getline(cin, temp);
        str.enqueue(temp);
    }
    cout << "The queue is full. Processing begins!\n";

    while (!str.isempty()) {
        str.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
    return 0;
}