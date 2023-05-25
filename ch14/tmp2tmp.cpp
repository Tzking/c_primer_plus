//
// Created by Tarryzking on 2023/5/25.
//
#include "iostream"

using std::cout;
using std::endl;

template<typename T>
void counts();

template<typename T>
void reports(T &);

template<typename T>
class HasFriend {
private:
    T item;
    [[maybe_unused]] static int n;
public:
    explicit HasFriend(const T &item) : item(item) { n++; }

    ~HasFriend() { n--; }

    friend void counts<T>();

    friend void reports<>(HasFriend<T> &);
};

template<typename T>
int HasFriend<T>::n = 0;

template<typename T>
void counts() {
    cout << "template size: " << sizeof(HasFriend<T>) << "; ";
    cout << "template counts(): " << HasFriend<T>::n << endl;
}

template<typename T>
void reports(T &h) {
    cout << h.item << endl;
}

int main() {
    counts<int>();
    HasFriend<int> hf1(10);
    HasFriend<int> hf2(20);
    HasFriend<double> hfd(10.5);
    reports(hf1);
    reports(hf2);
    reports(hfd);
    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();
    return 0;
}