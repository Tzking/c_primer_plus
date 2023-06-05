//
// Created by Tarryzking on 2023/6/2.
//
#include "iostream"
#include "fstream"
#include "iomanip"
#include "cstdlib"

const int Limit = 20;

struct planet {
    char name[Limit];
    double population;
    double g;
};

const char *file = "planets.dat";

inline void eat_line() { while (std::cin.get() != '\n') continue; }

int main() {
    using namespace std;
    planet p{};
    cout << fixed;

    fstream f_io;
    f_io.open(file, ios_base::in | ios_base::out | ios_base::binary);

    int ct = 0;
    if (f_io.is_open()) {
        f_io.seekg(0);
        cout << "Here are the current contents of the "
             << file << " file:\n";
        while (f_io.read((char *) &p, sizeof p)) {
            cout << ct++ << ": " << setw(Limit) << p.name << ": "
                 << setprecision(0) << setw(12) << p.population
                 << setprecision(2) << setw(6) << p.g << endl;
        }
        if (f_io.eof())
            f_io.clear();
        else {
            cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    } else {
        cerr << file << " could not be opened.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eat_line();
    if (rec < 0 || rec >= ct) {
        cerr << file << " Invalid record number.\n";
        exit(EXIT_FAILURE);
    }
    streampos place = rec * sizeof p;
    f_io.seekg(place);
    if (f_io.fail()) {
        cerr << "Error on attempted seek.\n";
        exit(EXIT_FAILURE);
    }

    f_io.read((char *) &p, sizeof p);
    cout << "Your selection:\n";
    cout << rec << ": " << setw(Limit) << p.name << ": "
         << setprecision(0) << setw(12) << p.population
         << setprecision(12) << setw(6) << p.g << endl;
    if (f_io.eof())
        f_io.clear();

    cout << "Enter planet name: ";
    cin.get(p.name, Limit);
    eat_line();
    cout << "Enter planetary population: ";
    cin >> p.population;
    cout << "Enter acceleration gravity: ";
    cin >> p.g;
    f_io.seekg(place);
    f_io.write((char *) &p, sizeof p);
    if (f_io.fail()) {
        cerr << "Error on attempted write.\n";
        exit(EXIT_FAILURE);
    }

    // display file after modify
    ct = 0;
    f_io.seekg(0);
    cout << "Here are the new contents of the " << file
         << "file:\n";
    while (f_io.read((char *) &p, sizeof p)) {
        cout << ct++ << ": " << setw(Limit) << p.name << ": "
             << setprecision(0) << setw(12) << p.population
             << setprecision(12) << setw(6) << p.g << endl;
    }
    f_io.close();
    cout << "Done.\n";
    return 0;
}