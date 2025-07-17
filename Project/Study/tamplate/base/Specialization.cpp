#include<iostream>
#include<string>
//模板类的全特化
//通用模板
template <typename T>
class Printer
{
public:
    void print(const T& value)
    {
        std::cout << value << std::endl;
    }
};

//全特化模板
template <>
class Printer<std::string>
{
public:
    void printf(const std::string& value)
    {
        std::cout << "全特化" << value << std::endl;
    }
};

//类模板偏特化
// 通用 Pair 类模板
template <typename T, typename U>
class Pair
{
public:
    T first;
    U second;

    Pair(T a, U b) : first(a), second(b)
    {
    }

    void print() const
    {
        std::cout << "General print" << std::endl;
        std::cout << "Pair: " << first << ", " << second << std::endl;
    }
};

//特例化
template <typename T, typename U>
class Pair<T, U*>
{
public:
    T first;
    U* second;

    Pair(T a, U* b) : first(a), second(b){}

    void print() const
    {
        std::cout << "Specialized  " << std::endl;
        std::cout << "Pair with pointer: " << first << ", " << *second << std::endl;
    }
};

//函数模板的特化
//通用模板
template <typename T>
void PrintValue(const T& value)
{
    std::cout << "General print" << value << std::endl;
}

//全特化
template <>
void PrintValue(const std::string& value)
{
    std::cout << "Specialized print for std::string: " << value << std::endl;
}

//变参模板
template <typename... Args>
void printAll(const Args&... args)
{
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

//日志记录器
//基础情况
void log(const std::string& msg)
{
    std::cout << msg << std::endl;
}

//至少有一个参数
template <typename T, typename... Args>
int main()
{
    //类模板全特化
    Printer<int> value;
    value.print(10);

    Printer<std::string> stringprinter;
    stringprinter.printf("hello,world");
    std::cout << "**************************************" << std::endl;

    //类模板偏特化
    double val = 3.14;
    Pair<std::string, double*> p2("Pi", &val);
    p2.print(); // 输出：Pair with pointer: Pi, 3.14
    std::cout << "**************************************" << std::endl;

    //函数模板特化
    PrintValue(42);
    PrintValue(3.14);
    PrintValue(std::string("Hello"));
    std::cout << "**************************************" << std::endl;

    //变参模板
    printAll("Hello", 'A', 1, 2.34);
    std::cout << "**************************************" << std::endl;

    return 0;
}
