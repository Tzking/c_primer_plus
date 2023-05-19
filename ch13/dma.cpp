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
    os << "Rating " << b.rating << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &l)
{
    os << (const baseDMA &) l;
    os << "Color: " << l.color << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream &os, const hasDMA &h)
{
    os << (const baseDMA &) h;
    os << "Style: " << h.style << std::endl;
    return os;
}

lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &b) : baseDMA(b)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

hasDMA::hasDMA(const char *c, const char *l, int r) : baseDMA(l, r)
{
    style = new char[std::strlen(c) + 1];
    std::strcpy(style, c);
}

hasDMA::hasDMA(const char *c, const baseDMA &b) : baseDMA(b)
{
    style = new char[std::strlen(c) + 1];
    std::strcpy(style, c);
}

hasDMA::hasDMA(const hasDMA &h) : baseDMA(h)
{
    style = new char[std::strlen(h.style) + 1];
    std::strcpy(style, h.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA &hasDMA::operator=(const hasDMA &h)
{
    if (this == &h)
        return *this;
    baseDMA::operator=(h);
    delete [] style;
    style = new char[std::strlen(h.style) + 1];
    std::strcpy(style, h.style);
    return *this;
}
