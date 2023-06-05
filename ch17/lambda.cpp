//
// Created by Tarryzking on 2023/6/4.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "ctime"

const long Size = 390000L;

int main() {
    using std::cout;
    std::vector<int> numbers(Size);

    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size << '\n';


    int count_3 = std::count_if(numbers.begin(), numbers.end(), [](int x) { return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count_3 << '\n';
    int count_13 = 0;
    std::count_if(numbers.begin(), numbers.end(), [&count_13](int x) { return count_13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count_13 << '\n';

    count_3 = count_13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
                  [&](int x) {
                      count_3 += x % 3 == 0;
                      count_13 += x % 13 == 0;
                  });
    cout << "Count of numbers divisible by 3: " << count_3 << '\n';
    cout << "Count of numbers divisible by 13: " << count_13 << '\n';
    return 0;
}