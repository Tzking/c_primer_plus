//
// Created by Tarryzking on 2023/5/24.
//

#ifndef DEMO_ARRAYTP_H
#define DEMO_ARRAYTP_H

#include "iostream"
#include "cstdlib"

template<class T, int n>
class Arraytp {
private:
    T arr[n];
public:
    Arraytp() = default;

    explicit Arraytp(const T &t);

    virtual T &operator[](int i);

    virtual T operator[](int i) const;
};

template<class T, int n>
T Arraytp<T, n>::operator[](int i) const {
    if (i < 0 || i >= n) {
        std::cerr << "Error in array limits: " << i
                  << " is out of range.\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

template<class T, int n>
T &Arraytp<T, n>::operator[](int i) {
    if (i < 0 || i >= n) {
        std::cerr << "Error in array limits: " << i
                  << " is out of range.\n";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

template<class T, int n>
Arraytp<T, n>::Arraytp(const T &t) {
    for (int i = 0; i < n; ++i) {
        arr[i] = t;
    }
}


#endif //DEMO_ARRAYTP_H
