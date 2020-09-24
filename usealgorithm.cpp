//
// Created by 11135 on 2020/8/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void print01(int val)
{
    cout << val << " ";
}

//仿函数
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

//常用遍历算法 for_each
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    
    for_each(v.begin(), v.end(), print01);
    
}


void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print02());
}


//常用遍历算法 transform
class Transform
{
public:
    int operator()(int v)
    {
        return v;
    }
};
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int> vTarget;
    vTarget.resize(v.size());   //目标容器需要提前开辟空间
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), print02());
}


//常用查找算法
//find

//查找 内置数据类型
void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //查找容器中是否有5这个元素
    auto it = find(v.begin(), v.end(), 5);
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else {
        cout << "找到 " << *it << endl;
    }
}

//查找自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    //重载== 底层find知道如何对比person数据类型
    bool operator==(const Person & p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};
void test05()
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

    auto it = find(v.begin(), v.end(), p2);
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到：" << it->m_Name << "年龄：" << it->m_Age << endl;
    }

}

//常用查找算法 find_if
//1、查找内置数据类型
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test06()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    auto it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到 " << *it << endl;
    }
}

//2、查找自定义数据类型
class Greater20
{
public:
    bool operator()(Person & p)
    {
        return p.m_Age > 20;
    }

    bool operator()(int v)
    {
        return v > 20;
    }
};

void test07()
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

    auto it = find_if(v.begin(), v.end(), Greater20());
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到 " << it->m_Name << endl;
    }
}


//常用查找算法 adjacent_find
void test08()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);

    auto it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到 " << *it << endl;
    }

}

//常用查找算法 binary_search
void test09()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    auto ret = binary_search(v.begin(), v.end(), 9);
    if (ret == true)
    {
        cout << "找到元素" << endl;
    }
    else
    {
        cout << "未找到元素" << endl;
    }
}


//常用查找算法 count
//1、统计内置数据类型
void test10()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(20);
    v.push_back(10);

    auto num = count(v.begin(), v.end(), 30);
    cout << "30的元素个数为：" << num << endl;
}

//2、自定义类型统计
void test11()
{
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 32);
    Person p3("张飞", 30);
    Person p4("赵云", 25);
    Person p5("曹操", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("诸葛亮", 35);

    auto num = count(v.begin(), v.end(), p);
    cout << "与诸葛亮年龄相同的人有：" << num << endl;

}

//常用查找算法 count_if
//统计内置数据类型
void test12()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    auto num = count_if(v.begin(), v.end(), Greater20());
    cout << "大于20的数有：" << num << endl;

}

//常用排序算法 sort
void test13()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), print02());

    cout << endl;
    //降序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), print02());
}


//常用排序算法 random_shuffle
void test14()
{
    srand((unsigned long)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //利用洗牌算法打乱
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), print02());
}

//常用排序算法 merge
void test15()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 10);
    }

    vector<int> vTraget;
    vTraget.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTraget.begin());
    for_each(vTraget.begin(), vTraget.end(), print02());

}

//常用排序算法 reverse
void test16()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "反转前：" << endl;
    for_each(v.begin(), v.end(), print02());
    cout << endl;

    reverse(v.begin(), v.end());
    cout << "反转后：" << endl;
    for_each(v.begin(), v.end(), print02());

}

// 常用拷贝和替换算法 copy
void test17()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int> v2;
    //开辟空间
    v2.resize(v.size());

    copy(v.begin(), v.end(), v2.begin());
    for_each(v2.begin(), v2.end(), print02());
}

// 常用拷贝和替换算法 replace
void test18()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);
    v.push_back(20);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), print02());
    cout << endl;

    //将20替换成2000
    replace(v.begin(), v.end(), 20, 2000);
    cout << "替换后：" << endl;
    for_each(v.begin(), v.end(), print02());

}

// 常用拷贝和替换算法 replace_if
class Greater30
{
public:
    bool operator()(int val)
    {
        return val >= 30;
    }
};


void test19()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);
    v.push_back(20);

    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), print02());
    cout << endl;

    //将20替换成2000
    replace_if(v.begin(), v.end(), Greater30(), 3000);
    cout << "替换后：" << endl;
    for_each(v.begin(), v.end(), print02());
}

// 常用拷贝和替换算法 swap
void test20()
{
    vector<int> v, v2;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        v2.push_back(i + 10);
    }

    cout << "交换前：" << endl;
    for_each(v.begin(), v.end(), print02());
    cout << endl;
    for_each(v2.begin(), v2.end(), print02());
    cout << endl;

    swap(v, v2);
    cout << "交换后：" << endl;
    for_each(v.begin(), v.end(), print02());
    cout << endl;
    for_each(v2.begin(), v2.end(), print02());
    cout << endl;


}


//常用算术生成算法 accumulate
void test21()
{
    vector<int> v;

    for (int i = 0; i <= 100; ++i) {
        v.push_back(i);
    }

    //参数3 起始累加值
    auto ret = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << ret << endl;
}


//常用算术生成算法 fill
void test22()
{
    vector<int> v;
    v.resize(10);

    //重新填充
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), print02());
}


//常用集合算法 set_intersection
void test23()
{
    vector<int> v1, v2, vTarget;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    //目标容器需要提前开辟空间
    //最特殊情况 大容器包含小容器 开辟空间取小容器的size
    vTarget.resize(min(v1.size(), v2.size()));

    //获取交集，返回目标容器的最后一个元素的迭代器地址
    auto it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), it, print02());

}


//常用集合算法 set_union
void test24()
{
    vector<int> v1, v2, vTarget;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    //目标容器空间开辟，最特殊的情况 两个容器没有交集
    vTarget.resize(v1.size() + v2.size());

    auto it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), it, print02());
}


//常用集合算法 set_difference
void test25()
{
    vector<int> v1, v2, vTarget;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    //目标容器空间开辟，最特殊的情况 两个容器没有交集 取两个容器中大的size作为目标容器开辟空间
    vTarget.resize(max(v1.size(), v2.size()));

    auto it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), it, print02());
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
//    test09();
//    test10();
//    test11();
//    test12();
//    test13();
//    test14();
//    test15();
//    test16();
//    test17();
//    test18();
//    test19();
//    test20();
//    test21();
//    test22();
//    test23();
//    test24();
    test25();
}