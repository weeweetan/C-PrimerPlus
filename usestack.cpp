//
// Created by 11135 on 2020/8/23.
//

#include <iostream>
#include <stack>
using namespace std;

void test01()
{
    stack<int> s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << "栈顶元素为：" << s.top() << endl;
    
        s.pop();
    }
    
    cout << "栈的大小为：" << s.size() << endl;
}


int main(int argc, char **argv)
{
    test01();
}