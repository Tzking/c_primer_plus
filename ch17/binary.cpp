//
// Created by Tarryzking on 2023/6/2.
//
#include "iostream"
#include "fstream"
#include "iomanip"
#include "cstdlib"

inline void eat_line() { while (std::cin.get() != '\n') continue; }

struct planet {
    char name[20];
    double population;
    double g;
};

const char *file = "planets.dat";

int main() {
    using namespace std;
    planet p{};
    cout << fixed << right;

    ifstream f_in;
    f_in.open(file, ios_base::in | ios_base::binary);
    if (f_in.is_open()) {
        cout << "Here are the current contents of the "
             << file << " file:\n";
        while (f_in.read((char *) &p, sizeof p)) {
            cout << setw(20) << p.name << ": "
                 << setprecision(0) << setw(12) << p.population
                 << setprecision(2) << setw(6) << p.g << endl;
        }
        f_in.close();
    }

    ofstream f_out(file, ios_base::out | ios_base::app | ios_base::binary);
    if (!f_out.is_open()) {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name (enter a blank line to quit):\n";
    cin.get(p.name, 20);
    while (p.name[0] != '\0') {
        eat_line();
        cout << "Enter planetary population: ";
        cin >> p.population;
        cout << "Enter planet's acceleration of gravity: ";
        cin >> p.g;
        eat_line();
        f_out.write((char *) &p, sizeof p);
        cout << "Enter planet name (enter a blank line to quit):\n";
        cin.get(p.name, 20);
    }
    f_out.close();

    f_in.clear();
    f_in.open(file, ios_base::in | ios_base::binary);
    if (f_in.is_open()) {
        cout << "Here are the new contents of the " << file << " file:\n";
        while (f_in.read((char *) &p, sizeof p)) {
            cout << setw(20) << p.name << ": "
                 << setprecision(0) << setw(12) << p.population
                 << setprecision(2) << setw(6) << p.g << endl;
        }
        f_in.close();
    }
    cout << "Done.\n";
    return 0;
}