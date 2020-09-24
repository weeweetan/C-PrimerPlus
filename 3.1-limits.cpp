//
// Created by 11135 on 2020/7/26.
//

#include <iostream>
#include <climits>

int main(int argc, char **argv)
{
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    //sizeof operator yields of types or of variable
    cout << "int is " << sizeof(int) << " bytes" << endl;
    cout << "short is " << sizeof n_short << " bytes" << endl;
    cout << "long is " << sizeof n_long << " bytes" << endl;
    cout << "long long is " << sizeof n_llong << " bytes" << endl;

    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
}