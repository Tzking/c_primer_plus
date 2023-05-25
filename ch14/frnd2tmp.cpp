//
// Created by Tarryzking on 2023/5/25.
//
#include "iostream"

using std::cout;
using std::endl;

template<typename T>
class HasFriend {
private:
    T item;
    [[maybe_unused]] static int n;
public:
    explicit HasFriend(const T &i) : item(i) { n++; }

    ~HasFriend() { n--; }

    friend void counts();

    friend void reports(HasFriend<T> &);

};

template<typename T>
int HasFriend<T>::n = 0;

void counts() {
    cout << "int count: " << HasFriend<int>::n << "; ";
    cout << "double count: " << HasFriend<double>::n << endl;
}

void reports(HasFriend<int> & h) {
    cout << "HasFriend<int>: " << h.item << endl;
}

void reports(HasFriend<double> &h) {
    cout << "HasFriend<double>: " << h.item << endl;
}

int main() {
    cout << "No objects declared: ";
    counts();
    HasFriend<int> hf1(10);
    cout << "After hf1 declared: ";
    counts();
    HasFriend<int> hf2(20);
    cout << "After hf2 declared: ";
    counts();
    HasFriend<double> hfd(10.5);
    cout << "After hfd declared: ";
    counts();
    reports(hf1);
    reports(hf2);
    reports(hfd);
    return 0;
}