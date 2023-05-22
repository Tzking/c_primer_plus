#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    // attributes
    typedef std::valarray<double> Scores;
    std::string name;
    Scores scores;

    // private methods
    std::ostream & arr_out(std::ostream & os) const;
public:
    // constuctors
    Student() : name("Null"), scores() {}
    explicit Student(const std::string & n) : name(n), scores() {}
    explicit Student(int s) : name("Null"), scores(s) {}
    Student(const std::string & n, int s) : name(n), scores(s) {}
    Student(const std::string & n, const Scores & s) : name(n), scores(s) {}
    Student(const std::string & n, const double * p_double, int x) : name(n), scores(p_double, x) {}
    ~Student() {}
    // public methods
    double average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;
    // friends
    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);

    friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif // STUDENT_HPP_