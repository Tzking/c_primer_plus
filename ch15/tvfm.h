//
// Created by Tarryzking on 2023/5/28.
//

#ifndef DEMO_TVFM_H
#define DEMO_TVFM_H

class Tv;

class Remote {
public:
    enum State {
        Off, On
    };
    enum {
        MinVal, MaxVal = 20
    };
    enum {
        Antenna, Cable
    };
    enum {
        TV, DVD
    };
private:
    int mode;
public:
    Remote(int m = TV) : mode(m) {}

    bool vol_up(Tv &tv);

    bool vol_down(Tv &tv);

    void on_off(Tv &tv);

    void channel_up(Tv &tv);

    void channel_down(Tv &tv);

    void set_mode(Tv &tv);

    void set_input(Tv &tv);

    void set_channel(Tv &tv, int c);
};

class Tv {
public:
    friend void Remote::set_channel(Tv &tv, int c);

    enum State {
        Off, On
    };
    enum {
        MinVal, MaxVal = 20
    };
    enum {
        Antenna, Cable
    };
    enum {
        TV, DVD
    };

    Tv(int s = Off, int mc = 125) : state(s), max_channel(mc), volume(5), channel(12), mode(Cable), input(TV) {}

    void on_off() {
        state = (state == On) ? Off : On;
    }

    bool is_on() const {
        return state == On;
    }

    bool vol_up();

    bool vol_down();

    void channel_up();

    void channel_down();

    void set_mode() {
        mode = (mode == Antenna) ? Cable : Antenna;
    }

    void set_input() {
        input = (input == TV) ? DVD : TV;
    }

    void settings() const;

private:
    int state;
    int volume;
    int max_channel;
    int channel;
    int mode;
    int input;
};

// Remote methods
inline bool Remote::vol_up(Tv &tv) { return tv.vol_up(); }

inline bool Remote::vol_down(Tv &tv) { return tv.vol_down(); }

inline void Remote::on_off(Tv &tv) { tv.on_off(); }

inline void Remote::channel_up(Tv &tv) { tv.channel_up(); }

inline void Remote::channel_down(Tv &tv) { tv.channel_down(); }

inline void Remote::set_mode(Tv &tv) { tv.set_mode(); }

inline void Remote::set_channel(Tv &tv, int c) { set_channel(tv, c); }

inline void Remote::set_input(Tv &tv) { tv.set_input(); }


#endif //DEMO_TVFM_H
