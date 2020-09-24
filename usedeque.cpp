//
// Created by 11135 on 2020/8/22.
//

#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &d)
{
    for (auto it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//deque构造函数
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int>d3(10, 100);
    printDeque(d3);

    deque<int>d4(d3);
    printDeque(d4);

}

//deque赋值操作
void test02()
{
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }

    printDeque(d1);

    //=赋值
    deque<int> d2 = d1;
    printDeque(d2);

    //assign
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);

}

//deque容器大小操作
void test03()
{
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    if (d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        cout << "d1大小为：" << d1.size() <<endl;
    }

    //重新指定大小
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}


//deque容器插入和删除
void test04()
{
    deque<int> d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    //尾删
    d1.pop_back();
    printDeque(d1);

    //头删
    d1.pop_front();
    printDeque(d1);

}


void test05()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);

    //按照区间插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}


void test06()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    auto it = d1.begin();
    it++;

    d1.erase(it);
    printDeque(d1);

    //按区间方式删除
    d1.erase(d1.begin(), d1.end());
    printDeque(d1);

}


//deque容器存取
void test07()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    //通过[]方式访问元素
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1[i] << " ";
    }
    cout << endl;

    //通过at
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1.at(i) << " ";
    }
    cout << endl;

    cout << "第一个元素为：" << d1.front() << endl;
    cout << "最后一个元素为：" << d1.back() << endl;

}


void test08()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    printDeque(d1);

    //排序 默认排序规则 从小到大
    sort(d1.begin(), d1.end());
    printDeque(d1);

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
    test08();
}