//
// Created by 11135 on 2020/8/10.
//

#ifndef C_PRIMER_STRBAD_H
#define C_PRIMER_STRBAD_H

#include <iostream>
class StringBad
{
private:
    char *str;
    int len;
    static int num_strings;
public:
    StringBad(const char *s);
    StringBad();
    ~StringBad();
    friend std::ostream &operator<<(std::ostream & os, const StringBad &st);
};

#endif //C_PRIMER_STRBAD_H
