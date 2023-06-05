//
// Created by Tarryzking on 2023/6/5.
//
#include "iostream"

class BS {
private:
    int q;
    double w;
public:
    BS() : q(0), w(0.0) {}

    BS(int k) : q(k), w(100.0) {}

    BS(double x) : q(-1), w(x) {}

    BS(int k, double x) : q(k), w(x) {}

    virtual void show() const { std::cout << q << ", " << w << std::endl; }
};

class DR : public BS {
private:
    short j;
public:
    using BS::BS;

    DR() : j(-100) {}

    DR(double x) : BS(2 * x), j(int(x)) {}

    DR(int i) : j(-2), BS(i, 0.5 * i) {}

    void show() const {
        std::cout << j << ", ";
        BS::show();
    }
};

int main() {
    DR o1;
    DR o2(18.81);
    DR o3(10, 18);
    o3.show();
}