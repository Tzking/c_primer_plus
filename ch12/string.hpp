#ifndef STRING_HPP_
#define STRING_HPP_

#include <iostream>
#include <cstring>

using std::ostream;
using std::istream;
using std::cout;

class String
{
private:
    char * str;
    int len;
    static int num_of_strings;
    static const int CINLIM = 80;
public:
    String();
    String(const char *);
    String(const String &); // 拷贝构造函数
    ~String();
    int length() const { return len; }

    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int);
    const char & operator[](int) const;

    friend bool operator>(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator==(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);
    friend istream & operator>>(istream &, String &);

    static int HowMany();
};

#endif // STRING_HPP_