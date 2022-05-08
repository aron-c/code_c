#pragma once
#include <iostream>
using namespace std;

template <class T>
class myArr
{

public:
    myArr(int cap);
    myArr(const myArr &arr);
    ~myArr();

    //重载等号operator=,防止出现a=b=c
    myArr &operator=(const myArr &arr);

    //尾插法
    void pushBack(const T &value);

    //尾删法
    void popBack();

    //通过下标访问数据
    T &operator[](int index);

    //返回数组容量
    int getCap();

    //返回数组大小
    int getSize();

private:
    T *pAddress; //指向堆区真实数组地址
    int m_cap;   //数组容量
    int m_size;  //数组大小
};

template <class T>
myArr<T>::myArr(int cap)
{
    // cout << "有参构造调用" << endl;
    this->m_cap = cap;
    this->m_size = 0;
    this->pAddress = new T[this->m_cap];
}

template <class T>
myArr<T>::myArr(const myArr &arr)
{
    this->m_cap = arr.m_cap;
    this->m_size = arr.m_size;
    // this->pAddress=arr.pAddress;//浅拷贝操作，指针不能直接复制

    //将原arr数据都进行复制
    for (int i = 0; i < this->m_size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }
}

template <class T>
myArr<T>::~myArr()
{
    if (this->pAddress != NULL)
    {
        // cout << "析构函数调用" << endl;
        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}

template <class T>
void myArr<T>::pushBack(const T &value)
{
    //判断文件大小
    if (this->m_cap == this->m_size)
    {
        return;
    }

    //末尾数据插入
    this->pAddress[this->m_size] = value;
    this->m_size++;
}

template <class T>
void myArr<T>::popBack()
{
    //数据为空
    if (this->m_size == 0)
    {
        return;
    }

    //访问不到最后一个数据，即为尾删
    this->m_size--;
}

template <class T>
myArr<T> &myArr<T>::operator=(const myArr &arr)
{
    // cout << "operator=调用" << endl;
    //先将堆区释放干净
    if (this->pAddress != NULL)
    {
        delete[] this->pAddress;
        this->pAddress = NULL;
        this->m_cap = 0;
        this->m_size = 0;
    }

    //将原数据拷贝
    this->m_cap = arr.m_cap;
    this->m_size = arr.m_size;
    this->pAddress = new T[this->m_size];
    for (int i = 0; i < this->m_size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }

    return *this;
}

template <class T>
T &myArr<T>::operator[](int index)
{
    return this->pAddress[index];
}

template <class T>
int myArr<T>::getCap()
{
    return this->m_cap;
}

template <class T>
int myArr<T>::getSize()
{
    return this->m_size;
}