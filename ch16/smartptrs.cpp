//
// Created by Tarryzking on 2023/5/29.
//
#include "iostream"
#include "string"
#include "memory"

class Report {
private:
    std::string str;
public:
    explicit Report(const std::string &str) : str(str) {
        std::cout << "Object created.\n";
    }

    virtual ~Report() {
        std::cout << "Object deleted.\n";
    }

    void comment() const {
        std::cout << str << std::endl;
    }
};

int main() {
    {
        std::unique_ptr<Report> ptr_1(new Report("using auto_ptr"));
        ptr_1->comment();
    }
}