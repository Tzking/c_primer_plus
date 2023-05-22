#include "worker.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// must implement virtual destructor, even if pure
Worker::~Worker() {}

void Worker::set()
{
    cout << "Enter worker's name: ";
    getline(cin, full_name);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;   
}

void Worker::show() const
{
    cout << "Name: " << full_name << endl;
    cout << "Employee ID: " << id << endl;
}

void Waitor::set()
{
    Worker::set();
    cout << "Enter waitor's paneche rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

void Waitor::show() const
{
    cout << "Category: waitor\n";
    Worker::show();
    cout << "Panache rating: " << panache << endl;

}

const char * Singer::pv[] = 
{
    "other", "alto", "contralto",
    "soprano", "bass", "baritone", "tenor"
};

void Singer::set()
{
    Worker::set();
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "    ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    while (cin >> voice && (voice < 0 || voice>= Vtypes))
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    while (cin.get() != '\n')
        continue;
}

void Singer::show() const
{
    cout << "Category: singer\n";
    Worker::show();
    cout << "Vocal range: " << pv[voice] << endl;
}
