#include <iostream>
using namespace std;

const double PI=3.14;

class MyClass
{
public:
    MyClass();
    MyClass(MyClass &&) = default;
    MyClass(const MyClass &) = default;
    MyClass &operator=(MyClass &&) = default;
    MyClass &operator=(const MyClass &) = default;
    ~MyClass();

private:
    
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
    cout << "hello world!" << endl;
    
    
    return 0;
}
