#include "dma.hpp"
#include <cstring>

baseDMA::baseDMA(const char *l, int r)
{
    label = new char [std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &b)
{
    label = new char[std::strlen(b.label) + 1];
    std::strcpy(label, b.label);
    rating = b.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA &baseDMA::operator=(const baseDMA &b)
{
    if (this == &b)
        return *this;
    delete [] label;
    label = new char[std::strlen(b.label) + 1];
    std::strcpy(label, b.label);
    rating = b.rating;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const baseDMA &b)
{
    os << "Label: " << b.label << std::endl;
    os << "RatingL " << b.rating << std::endl;
    return os;
}
