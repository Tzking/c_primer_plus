#ifndef DMA_HPP_
#define DMA_HPP_

#include <iostream>

class baseDMA
{
private:
    char * label;
    int rating;

public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & b);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & b);

    friend std::ostream & operator<<(std::ostream & os, const baseDMA & b);
};

class lacksDMA : public baseDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];

public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & b);
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & l);
};

class hasDMA : public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * c = "none", const char * l = "null", int r = 0);
    hasDMA(const char * c, const baseDMA & b);
    hasDMA(const hasDMA & h);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & h);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & h);
};

#endif // DMA_HPP_