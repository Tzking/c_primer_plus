//
// Created by Tarryzking on 2023/5/28.
//

#include "sales.h"

using std::string;

Sales::bad_index::bad_index(int i, const string &s) : std::logic_error(s), index(i) {}


Sales::Sales(int y) {
    year = y;
    for (double &gros: gross) {
        gros = 0;
    }
}

Sales::Sales(int y, const double *g, int n) {
    year = y;
    int limit = (n < MONTHS) ? n : MONTHS;
    int i;
    for (i = 0; i < limit; ++i) {
        gross[i] = g[i];
    }
    for (; i < MONTHS; ++i) {
        gross[i] = 0;
    }
}

double Sales::operator[](int i) const {
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

double &Sales::operator[](int i) {
    if (i < 0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}

Labeledsales::nbad_index::nbad_index(const string &m, int i, const string &s) : Sales::bad_index(i, s) {
    msg = m;
}

Labeledsales::Labeledsales(const string &s, int y) : Sales(y){
    label = s;
}

Labeledsales::Labeledsales(const string &s, int y, const double *g, int n) : Sales(y, g, n){
    label = s;
}

double Labeledsales::operator[](int i) const {
    if (i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}

double &Labeledsales::operator[](int i) {
    if (i < 0 || i >= MONTHS)
        throw nbad_index(Label(), i);
    return Sales::operator[](i);
}
