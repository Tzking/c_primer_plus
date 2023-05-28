//
// Created by Tarryzking on 2023/5/26.
//

#include <iostream>
#include "tv.h"

tv::tv(int s, int m)
        : state(s), max_channel(m), channel(2), mode(Cable), input(Tv) {}



bool tv::vol_down() {
    if (volume > MinVal) {
        volume--;
        return true;
    } else
        return false;
}

void tv::channel_up() {
    if (channel < max_channel) {
        channel++;
    } else
        channel = 1;
}

void tv::channel_down() {
    if (channel > 1) {
        channel--;
    } else
        channel = max_channel;
}

void tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "Tv is " << (state == Off ? "Off" : "On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "mode = "
             << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "input = "
             << (input == Tv ? "Tv" : "DvD") << endl;
    }
}

bool tv::is_on() const {
    return state == On;
}

void tv::on_off() {
    state = (state == On) ? Off : On;
}


bool tv::vol_up() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else
        return false;
}

