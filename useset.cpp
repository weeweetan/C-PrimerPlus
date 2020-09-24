//
// Created by 11135 on 2020/8/23.
//
#include <iostream>
#include <set>
using namespace std;

void printSet(set<int> &s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//set容器构造和赋值
void test01()
{
    set<int> s1;

    //插入数据只有insert方式
    s1.insert(10);
    s1.insert(20);
    s1.insert(60);
    s1.insert(30);
    s1.insert(50);
    s1.insert(40);

    //遍历容器
    //set容器特点：所有元素插入时自动排序
    //set容器不允许插入重复值
    printSet(s1);

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);

    //赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);

}


//set 容器大小和交换
void test02()
{
    set<int> s1;

    //插入数据
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    if (s1.empty())
    {
        cout << "s1为空" << endl;
    }
    else
    {
        cout << "s1不为空" << endl;
        cout << "s1的大小为：" << s1.size() << endl;
    }
}


void test03()
{
    set<int> s1;

    //插入数据
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);

    cout << "交换前:" << endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);
    cout << "交换后:" << endl;

    printSet(s1);
    printSet(s2);

}

//set容器 插入和删除
void test04()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    printSet(s1);

    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(30);
    printSet(s1);

}

//set容器查找和统计
void test05()
{
    //查找
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    auto pos = s1.find(30);
    if (pos != s1.end())
    {
        cout << "找到元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到元素：" << endl;
    }
}

void test06()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    auto num = s1.count(30);
    cout << "num = " << num <<endl;
}


//set 和multiset的区别
void test07()
{
    set<int> s1;

    pair<set<int>::iterator, bool> ret = s1.insert(10);
    if (ret.second)
    {
        cout << "第一次插入成功" << endl;
    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    ret = s1.insert(10);
    if (ret.second)
    {
        cout << "第一次插入成功" << endl;
    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    multiset<int> ms;
    //允许插入重复值
    ms.insert(10);
    ms.insert(10);

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << endl;
    }

}

// pair对组创建
void test08()
{
    //第一种方式
    pair<string, int> p("Tom", 20);
    cout << "姓名：" << p.first << "年龄：" << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 30);

    cout << "姓名：" << p2.first << "年龄：" << p2.second << endl;

}


class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};


//set容器排序
void test09()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //指定排序规则为从大到小
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);

    for (auto it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main(int argc, char **argv)
{
    test09();
}