//
// Created by 11135 on 2020/8/4.
//

#include <iostream>

template <typename T>
void Swap(T &a, T &b);

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


template <class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


template <class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max != i)
        {
            swap(arr[max], arr[i]);
        }
    }
}


template <class T, class U>
auto add(T t, U u) -> decltype(t+u)
{
    return t + u;
};

int main(int argc, char **argv)
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;

    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x, y);
    cout << "Now x, y = " << x << ", " << y << ".\n";

    char charArray[] = "abcdef";
    int len = sizeof(charArray) / sizeof(char);
    mySort(charArray, len);
    printArray(charArray, len);

    int intArray[] = {1,2,3,4,5,6,7,8,9};
    len = sizeof(intArray) / sizeof(int);
    mySort(intArray, len);
    printArray(intArray, len);

    cout << add(i, x) << endl;

    return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

