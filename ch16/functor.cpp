//
// Created by Tarryzking on 2023/6/1.
//
#include "iostream"
#include "list"
#include "iterator"
#include "algorithm"

template<class T>
class TooBig {
private:
    T cut_off;
public:
    explicit TooBig(const T &t) : cut_off(t) {}

    bool operator()(const T &t) { return t > cut_off; }
};

void show(int n) { std::cout << n << " "; }

int main() {
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f_100(100);
    int values[10] = {
            50, 100, 90, 180, 60, 210, 415, 88, 188, 201
    };
    list<int> yadayada(values, values + 10);
    list<int> etcatera(values, values + 10);

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), show);
    cout << endl;

    for_each(etcatera.begin(), etcatera.end(), show);
    cout << endl;

    yadayada.remove_if(f_100);
    etcatera.remove_if(TooBig<int>(200));
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), show);
    cout << endl;

    for_each(etcatera.begin(), etcatera.end(), show);
    cout << endl;
    return 0;
}