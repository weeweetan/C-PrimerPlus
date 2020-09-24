//
// Created by 11135 on 2020/8/7.
//

#ifndef C_PRIMER_MYTIME1_H
#define C_PRIMER_MYTIME1_H

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
    void Show() const;
};

#endif //C_PRIMER_MYTIME1_H
