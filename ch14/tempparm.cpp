//
// Created by Tarryzking on 2023/5/25.
//
#include "iostream"
#include "stacktp.h"

template<template<typename T> class Thing>
class Crab {
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab() = default;

    bool push(int a, double x) {
        return s1.push(a) && s2.push(x);
    }

    bool pop(int &a, double &x) {
        return s1.pop(a) && s2.pop(x);
    }
};

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    Crab<Stack> nebula;

    int n;
    double i;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end): \n";
    while (cin >> n >> i && n > 0 && i > 0) {
        if (!nebula.push(n, i))
            break;
    }
    while (nebula.pop(n, i)) {
        cout << n << ", " << i << endl;
    }
    cout << "Done.\n";
    return 0;
}