//
// Created by Tarryzking on 2023/5/24.
//
#include "iostream"
#include "arraytp.h"

int main() {
    using std::cout;
    using std::endl;
    Arraytp<int, 10> sums;
    Arraytp<double, 10> aves;
    Arraytp<Arraytp<int, 5>, 10> two_dee;

    int i, j;
    for (i = 0; i < 10; ++i) {
        sums[i] = 0;
        for (j = 0; j < 5; ++j) {
            two_dee[i][j] = (i + 1) * (j + 1);
            sums[i] += two_dee[i][j];
        }
        aves[i] = (double) sums[i] / 10;
    }

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 5; ++j) {
            cout.width(2);
            cout << two_dee[i][j] << " ";
        }
        cout << ": sum = ";
        cout.width(3);
        cout << sums[i] << ", average = " << aves[i] << endl;
    }

    cout << "Done.\n";
    return 0;
}
