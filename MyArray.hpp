//
// Created by 11135 on 2020/8/20.
//

#ifndef C_PRIMER_MYARRAY_HPP
#define C_PRIMER_MYARRAY_HPP


#include <memory>
#include <stdexcept>
#include <utility>

template <class T>
class MyArray
{
private:
    std::unique_ptr<T[]> pAddress;
    int m_Capacity;
    int m_Size;

    void swap(MyArray &other) noexcept
    {
        pAddress.swap(other.pAddress);
        std::swap(m_Capacity, other.m_Capacity);
        std::swap(m_Size, other.m_Size);
    }
public:
    MyArray(int capacity) : m_Capacity(capacity), m_Size(0)
    {
        if (capacity < 0)
            throw std::invalid_argument("MyArray capacity must be nonnegative");
        pAddress.reset(new T[capacity]);
    }


    MyArray(const MyArray & arr)
        : pAddress(new T[arr.m_Capacity]), m_Capacity(arr.m_Capacity), m_Size(arr.m_Size)
    {
        // RAII also releases the new array if an element assignment throws.
        for (int i = 0; i < this->m_Size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    MyArray &operator=(const MyArray & arr)
    {
        if (this != &arr)
        {
            MyArray copy(arr);
            swap(copy); // Commit only after every element has been copied.
        }

        return *this;
    }

    void Push_Back(const T & val)
    {
        if (this->m_Capacity == this->m_Size)
            return;

        this->pAddress[this->m_Size] = val;
        this->m_Size++;

    }

    void Pop_Back()
    {
        if (this->m_Size == 0)
            return;
        this->m_Size--;
    }


    T & operator[](int index)
    {
        return this->pAddress[index];
    }

    const T & operator[](int index) const
    {
        return this->pAddress[index];
    }

    int getCapacity() const noexcept
    {
        return this->m_Capacity;
    }

    int getSize() const noexcept
    {
        return this->m_Size;
    }

    ~MyArray() = default;
};

#endif //C_PRIMER_MYARRAY_HPP
