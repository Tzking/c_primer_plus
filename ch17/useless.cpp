//
// Created by Tarryzking on 2023/6/2.
//
#include "iostream"

using namespace std;

class Useless {
private:
    int n;
    char *pc;
    static int ct;

    void show_object() const;

public:
    Useless();

    explicit Useless(int k);

    Useless(int k, char c);

    Useless(const Useless &f);

    Useless(Useless &&f) noexcept;

    ~Useless();

    Useless operator+(const Useless &f) const;

    void show_data() const;
};

int Useless::ct = 0;

Useless::Useless() {
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    show_object();
}

Useless::Useless(int k) : n(k) {
    ++ct;
    cout << "int constructor called; number od objects: " << ct << endl;
    pc = new char[n];
    show_object();
}

Useless::Useless(int k, char c) : n(k) {
    ++ct;
    cout << "int, char constructor called; number od objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = c;
    }
    show_object();
}

Useless::Useless(Useless &&f) noexcept: n(f.n) {
    ++ct;
    cout << "move constructor called; number od objects: " << ct << endl;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    show_object();
}

Useless::~Useless() {
    cout << "destructor called; number od objects: " << ct << endl;
    cout << "deleted object:\n";
    show_object();
    delete[] pc;
}

Useless Useless::operator+(const Useless &f) const {
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; ++i) {
        temp.pc[i] = pc[i];
    }
    for (int i = n; i < temp.n; ++i) {
        temp.pc[i] = f.pc[i - n];
    }
    cout << "temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;
}

void Useless::show_object() const {
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void *) pc << endl;
}

void Useless::show_data() const {
    if (n == 0)
        cout << "(object empty)";
    else
        for (int i = 0; i < n; ++i) {
            cout << pc[i];
        }
    cout << endl;
}

Useless::Useless(const Useless &f) : n(f.n) {
    ++ct;
    cout << "copy constructor called; number od objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = f.pc[i];
    }
    show_object();
}

int main() {
    {
        Useless one(10, 'X');
        Useless two = one;
        Useless three(20, 'o');
        Useless four (one + three);
        cout << "object one: ";
        one.show_data();
        cout << "object two: ";
        two.show_data();
        cout << "object three: ";
        three.show_data();
        cout << "object four: ";
        four.show_data();
    }
}