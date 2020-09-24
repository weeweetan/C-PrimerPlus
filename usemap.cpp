//
// Created by 11135 on 2020/8/23.
//
#include <iostream>
#include <map>
using namespace std;


void printMap(map<int, int> &m)
{
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
    cout << endl;
}


//map构造和赋值
void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printMap(m);

    map<int, int> m2(m);
    printMap(m2);

    map<int, int> m3;
    m3 = m2;
    printMap(m3);
}


// map容器大小
void test02()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if (m.empty())
    {
        cout << "m为空" << endl;
    }
    else
    {
        cout << "m不为空" << endl;
        cout << "m的大小为" << m.size() << endl;
    }
}

// 交换map容器
void  test03()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));

    cout << "交换前：" << endl;
    printMap(m);
    printMap(m2);


    cout << "交换后：" << endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);

}


void test04()
{
    map<int, int> m;

    //插入
    //第一种
    m.insert(pair<int, int> (1, 10));

    //第二种
    m.insert(make_pair(2, 20));

    //第三种
    m.insert(map<int, int>::value_type(3, 30));

    //第四种，不建议插入，可以利用key访问value
    m[4] = 40;
    printMap(m);

    //删除
    m.erase(m.begin());
    printMap(m);

    // 按照key删除
    m.erase(3);
    printMap(m);

    //m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);

}

//map容器查找和统计
void test05()
{
    //查找
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end())
    {
        cout << "查找到元素 key = " << pos->first << " value = " << pos->second << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }


    //统计
    //map不允许插入重复key，count而言只能是0或者1
    int num = m.count(1);
    cout << "num = " << num << endl;

}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

// map容器排序
void test06()
{
    map<int, int, MyCompare> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << ", value = " << it->second << endl;
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
    test06();
}
