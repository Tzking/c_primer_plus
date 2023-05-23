//
// Created by Tarryzking on 2023/5/22.
//
#include <chrono>
#include "iostream"
#include "cstdlib"
#include "stcktp.h"

const int Num = 10;

int main() {
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::srand(seed);
    std::cout << "Please enter stack size: ";
    int stack_size;
    std::cin >> stack_size;

    Stack<const char *> s(stack_size);

    const char *in[Num] = {
            " 1: Hank Gilgamesh",
            " 2: Kiki Ishtar",
            " 3: Betty Rocker",
            " 4: Ian Flagranti",
            " 5: Wolfgan Kibble",
            " 6: Porti Koop",
            " 7: Joy Almondo",
            " 8: Xaverie Paprika",
            " 9: Juan Moore",
            " 10: Misha Mache"
    };
    const char *out[Num];

    int processed = 0;
    int next_in = 0;
    while (processed < Num) {
        if (s.isempty()) {
            s.push(in[next_in++]);
        } else if (s.isfull()) {
            s.pop(out[processed++]);
        } else if (std::rand() % 2 && next_in < Num) {
            s.push(in[next_in++]);
        } else
            s.pop(out[processed++]);
    }
    for (auto &i: out) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}