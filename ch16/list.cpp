//
// Created by Tarryzking on 2023/5/31.
//
#include "iostream"
#include "list"
#include "iterator"
#include "algorithm"

void output(const int &n) {
    std::cout << n << " ";
}

int main() {
    using namespace std;
    list<int> one(5, 2);
    int stuff[5] = {1, 2, 4, 8, 16};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "List one: ";
    for_each(one.begin(), one.end(), output);
    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), output);
    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), output);
    three.remove(2);
    cout << endl << "List three minus 2s: ";
    for_each(three.begin(), three.end(), output);
    three.splice(three.begin(), one);
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), output);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), output);
    three.unique();
    cout << endl << "List three after unique ";
    for_each(three.begin(), three.end(), output);
    three.sort();
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), output);
    two.sort();
    three.merge(two);
    cout << endl << "Sorted two merge into three: ";
    for_each(three.begin(), three.end(), output);
    cout << endl;
    return 0;
}