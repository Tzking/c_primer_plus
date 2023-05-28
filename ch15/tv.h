//
// Created by Tarryzking on 2023/5/26.
//

#ifndef DEMO_TV_H
#define DEMO_TV_H


class tv {
private:
    int state;
    int volume;
    int max_channel;
    int channel;
    int mode;
    int input;
public:
    friend class Remote;

    enum {
        Off, On
    };
    enum {
        MinVal, MaxVal = 20
    };
    enum {
        Antenna, Cable
    };
    enum {
        Tv, DvD
    };

    tv(int s = Off, int m = 125);

    void on_off();

    bool is_on() const;

    bool vol_up();

    bool vol_down();

    void channel_up();

    void channel_down();

    void set_mode() {
        mode = (mode == Antenna) ? Cable : Antenna;
    }

    void set_input() {
        input = (input == Tv) ? DvD : Tv;
    }

    void settings() const;


};

class Remote {
private:
    int mode;
public:
    Remote(int m = tv::Tv) : mode(m) {}

    bool vol_up(tv &t) {
        return t.vol_up();
    }

    bool vol_down(tv &t) {
        return t.vol_down();
    }

    void on_off(tv &t) {
        t.on_off();
    }

    void channel_up(tv &t) {
        t.channel_up();
    }

    void channel_down(tv &t) {
        t.channel_down();
    }

    void set_channel(tv &t, int c) {
        t.channel = c;
    }

    void set_mode(tv &t) {
        t.set_mode();
    }

    void set_input(tv &t) {
        t.set_input();
    }
};

#endif //DEMO_TV_H
