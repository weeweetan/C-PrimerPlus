//
// Created by 11135 on 2020/8/23.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

class Person
{
public:
    string m_Name;
    int m_Socre;

    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Socre = score;
    }
};


void createPerson(vector<Person> &v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}


void setSocre(vector<Person> &v)
{

//    default_random_engine e;
//    uniform_int_distribution<unsigned> u(60, 100);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        //将评委的分数放入deque容器中
        deque<int> d;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        cout << "选手：" << it->m_Name << "打分：" << endl;
        for (auto de = d.begin(); de != d.end(); de++)
        {
            cout << *de << " ";
        }
        cout << endl;

        //排序
        sort(d.begin(), d.end());

        //去除最高分和最低分
        d.pop_back();
        d.pop_front();

        //average
        int sum = 0;
        for (auto de = d.begin(); de != d.end(); de++)
        {
            sum += *de;
        }

        int avg = sum / d.size();

        //平均分赋值
        it->m_Socre = avg;
    }
}


void showScore(vector<Person> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << "平均分：" << it->m_Socre << endl;
    }

}

int main(int argc, char **argv)
{
    srand((unsigned int) time(NULL));

    //1、创建5名选手
    vector<Person> v;
    createPerson(v);

//    for (auto it = v.begin(); it != v.end(); it++)
//    {
//        cout << "姓名：" << (*it).m_Name << "分数：" << it->m_Socre << endl;
//    }

    //2、打分
    setSocre(v);

    showScore(v);

}