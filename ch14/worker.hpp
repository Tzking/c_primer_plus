#ifndef WORKER_HPP_
#define WORKER_HPP_

#include <string>

class Worker
{
private:
    std::string full_name;
    long id;
public:
    Worker() : full_name("null"), id(0L) {}
    Worker(const std::string & s, long n)
        : full_name(s), id(n) {}
    
    virtual ~Worker() = 0;
    virtual void set();
    virtual void show() const;
};

class Waitor : public Worker
{
private:
    int panache;
public:
    Waitor() : Worker(), panache(0) {}
    Waitor(const std::string & s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waitor(const Worker & w, int p = 0)
        : Worker(w), panache(p) {}
    void set();
    void show() const;    
};

class Singer : public Worker
{
protected:
    enum { other, alto, contralto, soprano,
            bass, baritone, tenor };
    enum { Vtypes = 7 };
private:
    static const char *pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other)
        : Worker(s, n), voice(v) {}
    Singer(const Worker & w, int v = other)
        : Worker(w), voice(v) {}
    void set();
    void show() const;
};

#endif // WORKER_HPP_