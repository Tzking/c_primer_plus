//
// Created by Tarryzking on 2023/6/1.
//
#include "iostream"
#include "vector"
#include "iterator"
#include "functional"

void show(double v) {
    std::cout.width(6);
    std::cout << v << ' ';
}

const int Limit = 6;

int main() {
    using namespace std;
    double arr_1[Limit] = {28, 29, 30, 35, 38, 59};
    double arr_2[Limit] = {63, 65, 69, 75, 80, 99};

    vector<double> gr8(arr_1, arr_1 + Limit);
    vector<double> m8(arr_2, arr_2 + Limit);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), show);
    cout << endl;
    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), show);
    cout << endl;

    vector<double> sum(Limit);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), show);
    cout << endl;

    vector<double> prod(Limit);
    transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), show);
    cout << endl;
    return 0;
}