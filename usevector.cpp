//
// Created by 11135 on 2020/8/21.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }
};

void MyPrint(int val)
{
    cout << val << endl;
}


void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

#if 0
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();          //指向容器中最后一个元素的下一个地址


    //第一种遍历方式
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }


    //第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
#endif

    //第三种遍历方式 利用STL提供遍历算法
    for_each(v.begin(), v.end(), MyPrint);
    
}

void test02()
{
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << "年龄：" << (*it).m_Age <<endl;
    }

}


void test03()
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; ++i) {
        v1.push_back(i + 1);
        v1.push_back(i + 2);
        v1.push_back(i + 3);
        v1.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++)
        {
            cout << *it1 << " ";
        }
        cout << endl;
    }


}


void printVector(vector<int> v1)
{
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


void test04()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1 为空" << endl;
    }
    else
    {
        cout << "v1 不为空" << endl;
        cout << "v1 容量为 " << v1.capacity() << endl;
        cout << "v1 大小为 " << v1.size() << endl;
    }

    v1.resize(15);
    printVector(v1);

}


void test05()
{
    vector<int> v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    printVector(v1);

    v1.pop_back();
    printVector(v1);

    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    v1.erase(v1.begin());
    printVector(v1);


}


void test06()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    //获取第一个元素
    cout << "第一个元素为：" << v1.front() << endl;

    //获取最后一个元素
    cout << "最后一个元素为：" << v1.back() << endl;

}

void test07()
{
    vector<int> v1;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "交换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}

//swap 收缩内存空间
void test08()
{
    vector<int> v1;

    for (int i = 0; i < 100000; ++i) {
        v1.push_back(i);
    }

    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;

    v1.resize(3);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;

    //巧用swap收缩
    vector<int>(v1).swap(v1);
    //vetoct<int>(v1) 匿名对象，执行完回收

    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl;
}


//预留空间
void test09()
{
    vector<int> v1;

    //利用reserve预留空间
    v1.reserve(100000);
    int num = 0; //统计开辟次数
    int *p = NULL;
    for (int i = 0; i < 100000; ++i) {
        v1.push_back(i);

        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }

    cout << "num = " << num << endl;

}

int main(int argc, char **argv)
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    //test08();
    test09();
}