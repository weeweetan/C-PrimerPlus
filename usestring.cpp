//
// Created by 11135 on 2020/8/21.
//

#include <iostream>
#include <string>

using namespace std;

void test01()
{
    string s1;
    
    const char * str = "hello world";
    string s2(str);
    
    cout << "s2 = " << s2 << endl;
    
    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;


}


void test02()
{
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;

    string str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("hello C++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello C++", 5);
    cout << "str5 = " << str5 << endl;

}

void test03()
{
    string str1 = "我";
    str1 = str1 + "爱玩游戏";
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << str3 << endl;

}

void test04()
{
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if (pos == -1)
        cout << "没有找到字符串" << endl;
    else
        cout << "pos = " << pos << endl;

    pos = str1.rfind("de");
    if (pos == -1)
        cout << "没有找到字符串" << endl;
    else
        cout << "pos = " << pos << endl;

}


void test05()
{
    string str1 = "abcdefg";

    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;
}


void test06()
{
    string str1 = "xello";
    string str2 = "hello";
    if (str1.compare(str2) == 0)
        cout << "str1 == str2" << endl;
    else if (str1.compare(str2) > 0)
        cout << "str1 > str2" << endl;
    else
        cout << "str1 < str2" << endl;
}

void test07()
{
    string str1 = "hello";
    cout << "str = " << str1 << endl;

    for (int i = 0; i < str1.size(); ++i) {
        cout << str1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < str1.size(); ++i) {
        cout << str1.at(i) << " ";
    }
    cout << endl;

}


void test08()
{
    string str1 = "hello";
    str1.insert(1, "111");
    cout << "str1 = " << str1 << endl;

    str1.erase(1, 3);
    cout << "str1 = " << str1 << endl;

}


void test09()
{
    string str1 = "abcdefg";
    string str2 = str1.substr(1, 3);
    cout << "str1 = " << str2 << endl;

    string str3 = "zhangsan@sina.com";
    int pos = str3.find("@");
    string str4 = str3.substr(0, pos);
    cout << "str4 = " << str4 << endl;
}

int main(int argc, char **argv)
{
    //test01();
    //test02();
    //test03();
    //test04();
//    test05();
//    test06();
//    test07();
//    test08();
    test09();
}