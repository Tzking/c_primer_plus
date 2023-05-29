//
// Created by Tarryzking on 2023/5/28.
//
#include "iostream"
#include "sales.h"

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double vals_1[12] = {
            1220, 1100, 1122, 2212, 1232, 2334,
            2884, 2393, 3302, 2922, 3002, 2544
    };

    double vals_2[12] = {
            12, 11, 22, 21, 32, 34,
            28, 29, 33, 29, 32, 35
    };

    Sales sales_1(2011, vals_1, 12);
    Labeledsales sales_2("Blogstar", 2012, vals_2, 12);

    cout << "First try block:\n";
    try {
        int i;
        cout << "Year = " << sales_1.Year() << endl;
        for (i = 0; i < 12; ++i) {
            cout << sales_1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year = " << sales_2.Year() << endl;
        cout << "Label = " << sales_2.Label() << endl;
        for (i = 0; i <= 12; ++i) {
            cout << sales_2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    } catch (Labeledsales::nbad_index &nbad) {
        cout << nbad.what();
        cout << "Company: " << nbad.label_val() << endl;
        cout << "bad index: " << nbad.index_val() << endl;
    } catch (Sales::bad_index &bad) {
        cout << bad.what();
        cout << "bad index: " << bad.index_val() << endl;
    }
    cout << "End of try block:\n";
    try {
        sales_2[2] = 37.5;
        sales_1[20] = 23345;
    } catch (Labeledsales::nbad_index &nbad) {
        cout << nbad.what();
        cout << "Company: " << nbad.label_val() << endl;
        cout << "bad index: " << nbad.index_val() << endl;
    } catch (Sales::bad_index &bad) {
        cout << bad.what();
        cout << "bad index: " << bad.index_val() << endl;
    }
    cout << "Done.\n";
    return 0;
}