//
// Created by 11135 on 2020/8/23.
//

#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &l)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);


    //区间构造
    list<int> L2(L1.begin(), L1.end());
    printList(L2);


    //拷贝构造
    list<int> L3(L2);
    printList(L3);

    list<int> L4(10, 100);
    printList(L4);

}


void test02()
{
    list<int> L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    //operator=赋值
    list<int> L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    printList(L3);

    list<int> L4;
    L4.assign(10, 100);
    printList(L4);


}


void test03()
{
    list<int> L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    list<int> L2;
    L2.assign(10, 100);

    cout << "交换前" << endl;
    printList(L1);
    printList(L2);

    L1.swap(L2);

    cout << "交换后" << endl;
    printList(L1);
    printList(L2);

}


void test04()
{
    list<int> L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    if (L1.empty())
    {
        cout << "L1为空" << endl;
    }
    else
    {
        cout << "L1不为空" << endl;
        cout << "L1的元素个数为：" << L1.size() << endl;
    }

    L1.resize(10, 5);
    printList(L1);

}


void test05()
{
    list<int> l;

    //尾插
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    //头插
    l.push_front(100);
    l.push_front(200);
    l.push_front(300);

    printList(l);

    //尾删
    l.pop_back();
    printList(l);

    //头删
    l.pop_front();
    printList(l);

    //insert插入
    auto it = l.begin();

    l.insert(++it, 1000);
    printList(l);

    //删除
    it = l.begin();
    l.erase(++it);
    printList(l);

    //移除
    l.push_back(1000);
    printList(l);
    l.remove(1000);
    printList(l);
}


//list容器存取
void test06()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    cout << "第一个元素为：" << l1.front() << endl;
    cout << "最后一个元素为：" << l1.back() << endl;
    //l1.front();

    //迭代器不支持随机访问
    list<int>::iterator it = l1.begin();
    //it++/it-- 支持
    //it = it + 1 不支持
}


//list容器反转和排序
void test07()
{
    list<int> l1;
    l1.push_back(60);
    l1.push_back(20);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);
    l1.push_back(70);

    cout << "反转前：" << endl;
    printList(l1);

    cout << "反转后：" << endl;
    l1.reverse();
    printList(l1);

}

bool myCompare(int v1, int v2)
{
    return v1 > v2;
}


// 排序
void test08()
{
    list<int> l1;
    l1.push_back(60);
    l1.push_back(20);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);
    l1.push_back(70);

    cout << "排序前：" << endl;
    printList(l1);

    //不支持随机访问的迭代器，不能使用标准算法 sort(l1.begin, l1.end)
    //不支持随机访问的迭代器，内部会提供对应的一些算法

    cout << "排序后：" << endl;
    l1.sort();              //默认排序规则为升序
    printList(l1);

    l1.sort(myCompare);
    printList(l1);
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