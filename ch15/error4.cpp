//
// Created by Tarryzking on 2023/5/28.
//

#include "iostream"
#include "cmath"
#include "exc_mean.h"

double h_mean(double a, double b);

double g_mean(double a, double b);

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            z = h_mean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            z = g_mean(x, y);
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Enter next two numbers <q to quit>: ";
        } catch (bad_hmean &h) {
            h.msg();
            cout << "Try again.\n";
            continue;
        } catch (bad_gmean &g) {
            cout << g.msg();
            cout << "Values used: " << g.val_1 << ", "
                 << g.val_2 << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Done.\n";
    return 0;
}

double h_mean(double a, double b) {
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double g_mean(double a, double b) {
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}