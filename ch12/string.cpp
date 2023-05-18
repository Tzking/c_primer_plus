#include "string.hpp"

int String::num_of_strings = 0;

String::String()
{
    len = 0;
    str = new char[1];
    str = 0;
    num_of_strings++;
}

String::String(const String & s)
{
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    num_of_strings++;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_of_strings++;
}

String::~String()
{
    --num_of_strings;
    delete [] str;
}

String &String::operator=(const String & s)
{
    if (this == &s)
    {
        return *this;
    }
    delete [] str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    return *this;
}

String &String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char &String::operator[](int i)
{
    return str[i];
}

const char &String::operator[](int i) const
{
    return str[i];
}

int String::HowMany()
{
    return num_of_strings;
}

bool operator<(const String & s1, const String & s2)
{
    return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator==(const String & s1, const String & s2)
{
    return (std::strcmp(s1.str, s2.str) == 0);
}

ostream &operator<<(ostream & os, const String & s)
{
    os << s.str;
    return os;
}

istream &operator>>(istream & is, String & s)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        s = temp;
    while (is && is.get() != '\n')
    {
        continue;
    }
    return is;
}

bool operator>(const String & s1, const String & s2)
{
    return s2 < s1;
}