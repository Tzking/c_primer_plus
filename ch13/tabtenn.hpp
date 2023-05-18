#ifndef TABTENN_HPP_
#define TABTENN_HPP_

#include <string>
using std::string;

class TableTennisPlayer
{
private:
    string first_name;
    string last_name;
    bool has_Table;
public:
    TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    
    void Name() const;
    bool hasTable() const { return has_Table; }
    void resetTable(bool b) { has_Table = b; }
};

class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & ttp);
    unsigned int Rating() const { return rating; }
    void resetRating(unsigned int r) { rating = r; }
};

#endif // TABTENN_HPP_