//
// Created by Tarryzking on 2023/5/28.
//

#ifndef DEMO_EXC_MEAN_H
#define DEMO_EXC_MEAN_H

#include "iostream"

class bad_hmean {
private:
    double val_1;
    double val_2;
public:
    bad_hmean(double val1, double val2) : val_1(val1), val_2(val2) {}

    void msg();
};

inline void bad_hmean::msg() {
    std::cout << "hmean(" << val_1 << ", " << val_2 << "): "
              << "invaild arguments: a = -b\n";
}

class bad_gmean {
public:
    double val_1;
    double val_2;

    bad_gmean(double val1, double val2) : val_1(val1), val_2(val2) {}

    const char *msg();
};

const char *bad_gmean::msg() {
    return "gmean() arguments should be >= 0.\n";
}


#endif //DEMO_EXC_MEAN_H
