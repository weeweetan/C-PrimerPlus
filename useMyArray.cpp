//
// Created by 11135 on 2020/8/20.
//
#include <iostream>
#include "MyArray.hpp"

using namespace std;

void printIntArray(const MyArray<int> & arr)
{
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << endl;
    }
}

void test01()
{
    MyArray<int> arr1(5);

    for (int i = 0; i < 5; ++i) {
        arr1.Push_Back(i);
    }

    cout << "arr1的打印输出为：" << endl;
    printIntArray(arr1);
    MyArray<int> arr2(arr1);
    MyArray<int> arr3(1);
    arr3 = arr1;
    arr1[0] = 99;

    cout << "复制后的arr2保持原值：" << endl;
    printIntArray(arr2);
    MyArray<int> &alias = arr3;
    arr3 = alias;
    cout << "自赋值后的arr3保持原值：" << endl;
    printIntArray(arr3);
}

int main()
{
    test01();
}
