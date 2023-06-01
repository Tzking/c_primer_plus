//
// Created by Tarryzking on 2023/6/1.
//
#include "iostream"
#include "string"
#include "map"
#include "algorithm"

typedef int key_type;
typedef std::pair<const key_type, std::string> my_pair;
typedef std::multimap<key_type, std::string> map_code;

int main() {
    using namespace std;
    map_code codes;

    codes.insert(my_pair(415, "San Francisco"));
    codes.insert(my_pair(510, "Oakland"));
    codes.insert(my_pair(718, "Brooklyn"));
    codes.insert(my_pair(718, "Staten Island"));
    codes.insert(my_pair(415, "San Rafael"));
    codes.insert(my_pair(510, "Berkeley"));

    cout << "Number of cities with area code 415: "
         << codes.count(415) << endl;
    cout << "Number of cities with area code 718: "
         << codes.count(718) << endl;
    cout << "Number of cities with area code 510: "
         << codes.count(510) << endl;
    cout << "Area code\tCity\n";
    map_code::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it)
        cout << "      " << (*it).first << "\t"
             << (*it).second << endl;
    pair<map_code::iterator, map_code::iterator> range = codes.equal_range(718);
    cout << "Cites with area code 718:\n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;
    return 0;
}