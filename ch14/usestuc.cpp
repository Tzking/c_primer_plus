#include <iostream>
#include "student.hpp"

using std::cin;
using std::cout;
using std::endl;

void set(Student & s, int n);
const int pupils = 3;
const int quizzes = 5;

int main(int argc, char const *argv[])
{
    Student ada[pupils] = 
        {
            Student(quizzes),
            Student(quizzes),
            Student(quizzes)
        };
    int i;
    for ( i = 0; i < pupils; i++)
        set(ada[i], quizzes);
    cout << "\nStudent List:\n";
    for ( i = 0; i < pupils; i++)
        cout << ada[i].Name() << endl;
    cout << "\nResults:";
    for ( i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].average() << endl;
    }
    cout << "Done.\n";
    return 0;
}

void set(Student &s, int n)
{
    cout << "Please enter the sutdent's name: ";
    getline(cin, s);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> s[i];
    while (cin.get() != '\n')
        continue;
}