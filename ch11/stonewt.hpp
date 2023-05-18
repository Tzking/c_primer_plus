#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>
#include "stonewt.hpp"

using std::cout;

class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();

    void show_lbs() const;
    void show_stn() const;
};

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = 0;
    pds_left = 0;
    pounds = 0;
}

Stonewt::~Stonewt()
{
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds.\n";
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds.\n";
}

#endif