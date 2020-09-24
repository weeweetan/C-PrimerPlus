//
// Created by 11135 on 2020/8/7.
//

#ifndef C_PRIMER_MYTIME3_H
#define C_PRIMER_MYTIME3_H

#include <iosfwd>

class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;
    Time operator*(double n) const;
    friend Time operator*(double m, const Time &t) { return t*m;}
    friend std::ostream & operator <<(std::ostream & os, const Time &t);
};

#endif //C_PRIMER_MYTIME3_H
