//
// Created by Tarryzking on 2023/5/31.
//
#include "iostream"
#include "string"
#include "set"
#include "algorithm"
#include "iterator"

int main() {
    using namespace std;
    const int N = 6;
    string s_1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s_2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A(s_1, s_1 + N);
    set<string> B(s_2, s_2 + N);

    ostream_iterator<string, char> out(cout, " ");
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;

    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s_3("grungy");
    C.insert(s_3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;
    return 0;
}