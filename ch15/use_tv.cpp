//
// Created by Tarryzking on 2023/5/26.
//
#include "iostream"
#include "tv.h"

int main() {
    using std::cout;
    tv s42;
    cout << "Initial setting for 42\" Tv:\n";
    s42.settings();
    s42.on_off();
    s42.channel_up();
    cout << "\nAdjust settings for 42\" Tv:\n";
    s42.channel_up();
    cout << "\nAdjusted settings for 42\" Tv:\n";
    s42.settings();

    Remote grey;

    grey.set_channel(s42, 10);
    grey.vol_up(s42);
    grey.vol_up(s42);
    cout << "\n42\" settings after using remote:\n";
    s42.settings();

    tv s58(tv::On);
    s58.set_mode();
    grey.set_channel(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();
    return 0;
}