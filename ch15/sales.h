//
// Created by Tarryzking on 2023/5/28.
//

#ifndef DEMO_SALES_H
#define DEMO_SALES_H

#include "iostream"

class Sales {
public:
    enum {
        MONTHS = 12
    };

    class bad_index : public std::logic_error {
    private:
        int index;
    public:
        explicit bad_index(int i, const std::string &s = "Index error in Sales object.\n");

        int index_val() const { return index; }

        virtual ~bad_index() throw() {}
    };

    explicit Sales(int y = 0);

    Sales(int y, const double *g, int n);

    virtual ~Sales() {}

    int Year() const { return year; }

    virtual double operator[](int i) const;

    virtual double & operator[](int i);

private:
    double gross[MONTHS];
    int year;
};

class Labeledsales : public Sales {
public:
    class nbad_index : public Sales::bad_index {
    private:
        std::string msg;
    public:
        nbad_index(const std::string &label, int i, const std::string &s = "Index error in Labeledsales object.\n");

        const std::string &label_val() const { return msg; }

        virtual ~nbad_index() throw() {}
    };
    explicit Labeledsales(const std::string &s = "none", int y = 0);

    Labeledsales(const std::string &s, int y, const double *g, int n);

    virtual ~Labeledsales() {}

    const std::string & Label() const { return label; }

    virtual double operator[](int i) const;

    virtual double & operator[](int i);
private:
    std::string label;
};

#endif //DEMO_SALES_H
