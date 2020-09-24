//
// Created by 11135 on 2020/8/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>       //内建函数对象仿函数
using namespace std;

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

//函数对象在使用时，可以像普通函数那样使用，可以有参数，也可以有返回值
void test01()
{
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}


//函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint()
    {
        count = 0;
    }
    void operator()(string test)
    {
        cout << test << endl;
        count++;
    }
    int count;
};

void test02()
{
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");

    cout << "myPrint的调用次数为：" << myPrint.count << endl;
}


//函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}

void test03()
{
    MyPrint myPrint;
    doPrint(myPrint, "hello C++");
}

//仿函数 返回类型是bool类型数据，成为谓词
//一元谓词
class GreaterFive
{
public:
    bool operator()(int v)
    {
        return v > 5;
    }
};

void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //GreaterFive()匿名函数对象
    auto it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了大于5的数字" << *it << endl;
    }
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

//二元谓词
void test05()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);

    sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "----------------------" << endl;

    //使用函数对象 改变算法策略，变为排序规则从大到小
    sort(v.begin(), v.end(), MyCompare());

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//内建仿函数
//negate 一元仿函数 取反仿函数
void test06()
{
    negate<int> n;
    cout << n(50) << endl;
}


void test07()
{
    plus<int> p;
    cout << p(10, 20) << endl;
}


//内建函数对象 关系仿函数
//大于 greater
void test08()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}


//内建函数对象 逻辑仿函数
//逻辑非
void test09()
{
    vector<bool> v;

    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;


    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}


int main(int argc, char **argv)
{
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test08();
    test09();
}