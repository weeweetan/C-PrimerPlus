//
// Created by 11135 on 2020/8/14.
//

#include <iostream>
#include <string>
#include "acctabc.h"
const int CLIENTS = 4;

int main(int argc, char **argv)
{
    using std::cin;
    using std::cout;
    using std::endl;

    AcctABC *p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; ++i) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or " << "2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout << "Enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate " << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }

    cout << endl;
#if 0
    for (int i = 0; i < CLIENTS; ++i) {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; ++i) {
        delete p_clients[i];
    }
#endif

    for (auto item : p_clients)
    {
        item->ViewAcct();
        cout << endl;
    }

    for(auto item : p_clients)
    {
        delete item;
    }

    cout << "Done.\n";
    return 0;

}