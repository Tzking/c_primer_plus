//
// Created by Tarryzking on 2023/5/28.
//
#include "iostream"
#include "cstdlib"
#include "ctime"

using std::cout;

class Grand {
private:
    int hold;
public:
    explicit Grand(int hold) : hold(hold) {}

    virtual void Speak() const { cout << "I am a grand class.\n"; }

    virtual int Value() const { return hold; }
};

class Superb : public Grand {
public:
    explicit Superb(int hold) : Grand(hold) {}

    void Speak() const override { cout << "I am a Superb Class.\n"; }

    virtual void Say() const {
        cout << "I hold the superb value of " << Value() << ".\n";
    }
};

class Magnificent : public Superb {
private:
    char c;
public:
    Magnificent(int hold, char c) : Superb(hold), c(c) {}

private:
    void Speak() const override {
        cout << "I am a magnificent class.\n";
    }

    void Say() const override {
        cout << "I hold the charactor " << c
             << " and the integer " << Value() << ".\n";
    }
};

Grand *GetOne();

int main() {
    std::srand(std::time(0));
    Grand *p_grand;
    Superb *p_superb;
    for (int i = 0; i < 5; ++i) {
        p_grand = GetOne();
        p_grand->Speak();
        if (p_superb == dynamic_cast<Superb *>(p_grand))
            p_superb->Say();
    }
    return 0;
}

Grand *GetOne() {
    Grand *p;
    switch (std::rand() % 3) {
        case 0:
            p = new Grand(std::rand() % 100);
            break;
        case 1:
            p = new Superb(std::rand() % 100);
            break;
        case 2:
            p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
            break;
    }
    return p;
}