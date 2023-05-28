//
// Created by Tarryzking on 2023/5/28.
//
#include "iostream"
#include "cstdlib"

double h_mean(double a, double b);

double h_mean(double a, double b) {
    if (a == -b) {
        std::cout << "untenable arguments to h_mean()\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}

int main() {
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y) {
        z = h_mean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y
                  << " is " << z << std::endl;
        std::cout << "Enter two numbers <q to quit>: ";
    }
    std::cout << "Done.\n";
    return 0;
}
