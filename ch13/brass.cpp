#include <iostream>
#include "brass.hpp"

using std::cout;
using std::endl;
using std::string;

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precions;

format setFormat();
void restore(format f, precions p);

Brass::Brass(const std::string &s, long an, double bal)
{
    full_name = s;
    account_num = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed; "
            << "deposit is cancelled.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    // set up ###.## format
    format init = setFormat();
    precions pre = cout.precision(2);

    if (amt < 0)
        cout << "Withdrawal amount must be positive; "
            << "withdraw canceled.\n";
    else if (amt <= balance)
        balance -= amt;
    else 
        cout << "Withdrawal amout of $" << amt
            << " exceeds your balance.\n"
            << "Withdrawal cancelled.\n";
    restore(init, pre);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::Viewaccount() const
{
    // set up ###.## format
    format init = setFormat();
    precions pre = cout.precision(2);

    cout << "Client: " << full_name << endl;
    cout << "Account Number: " << account_num << endl;
    cout << "Balance: $" << balance << endl;

    restore(init, pre);
}

Brass_plus::Brass_plus(const std::string &s, long an, double bal, double ml, double r)
    : Brass(s, an, bal)
{
    max_loan = ml;
    owesbank = 0.0;
    rate = r;
}

Brass_plus::Brass_plus(const Brass &b, double ml, double r)
    : Brass(b)
{
   max_loan = ml;
   owesbank = 0.0;
   rate = r; 
}

void Brass_plus::Viewaccount() const
{
    // set up ###.## format
    format init = setFormat();
    precions pre = cout.precision(2);

    Brass::Viewaccount();
    cout << "Maximum loan: $" << max_loan << endl;
    cout << "Owed to bank: $" << owesbank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%.\n";

    restore(init, pre);
}

void Brass_plus::Withdraw(double amt)
{
    // set up ###.## format
    format init = setFormat();
    precions pre = cout.precision(2);

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt <= bal + max_loan - owesbank)
    {
        double advance = amt = bal;
        owesbank += advance * (rate + 1);
        cout << "Back advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "Credit limit excceded. transaction cancelled.\n";
    
    restore(init, pre);
}

format setFormat()
{
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precions p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}