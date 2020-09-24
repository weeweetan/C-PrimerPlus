//
// Created by 11135 on 2020/8/23.
//

#include <iostream>
#include <queue>
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

void test01()
{
    queue<Person> q;
    
    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);
    
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    
    while (!q.empty())
    {
        cout << "队头元素 ---- 姓名：" << q.front().m_Name << endl;
        cout << "队尾元素 ---- 姓名：" << q.back().m_Name << endl;
        
        q.pop();
    }
    
}


int main(int argc, char **argv)
{
    test01();
}