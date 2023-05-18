#ifndef BRASS_HPP_
#define BRASS_HPP_

#include <string>

// Brass Account Class
class Brass
{
private:
    std::string full_name;
    long account_num;
    double balance;  
public:
    Brass(const std::string & s = "Null body", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void Viewaccount() const;
    virtual ~Brass() { }
};

// Brass Plus
class Brass_plus : public Brass
{
private:
    double max_loan;
    double rate;
    double owesbank;
public:
    Brass_plus(const std::string & s = "Null body", long an = -1,
            double bal = 0.0, double ml = 500, double r = 0.11125);
    Brass_plus(const Brass & b, double ml = 500, double r = 0.11135);
    virtual void Viewaccount() const;
    virtual void Withdraw(double amt);
    void resetMax(double m) { max_loan = m; }
    void resetRate(double r) { rate = r; }
    void resetOwes() { owesbank = 0; }
};

#endif // BRASS_HPP_