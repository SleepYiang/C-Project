#include<iostream>
#include<string>
#include<vector>
#include<list>
//显示最大值函数
template<typename T >
T maxValue(T a,T b)
{
    return (a>b)?a:b;
}

//类模板
template<typename T,typename U>
class Pair
{
public:
    T first;
    U second;
    Pair(T a,U b):first(a),second(b){}
    void print()
    {
        std::cout<<"Pair:"<<first<<","<<second<<std::endl;
    }
};

//类型参数      参数类型为任意的参数类型
template<typename T >
class Myclass
{
public:
    T data;
};
//非类型参数     参数类型受非参数类型的影响
template<typename T ,int N>
class Array
{
public:
    T data[N];
};

//固定大小的数组类
template<typename T ,int N>
class FixedArray
{
public:
    T data[N];
    T &operator[](std::size_t index)
    {
        return data[index];
    }
    void printf() const
    {
        for (std::size_t i = 0; i < N; i++)
        {
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

//模板模板参数
template<template<typename ,typename> class container>
class Vector{};

//容器适配器
template <template <typename, typename> class Container, typename T>
class ContainerPrinter {
public:
    void print(const Container<T, std::allocator<T>>& container) {
        for(const auto& elem : container)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
};
// 使用折叠表达式的printAll
template <typename... Args>
void printAll(const Args&... args) {
    // 使用左折叠展开参数包，并在每个参数之后输出一个空格
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

int main()
{
    //显示最大值函数
    std::cout<<maxValue<int>(1,2)<<std::endl;           //int类型
    std::cout<<maxValue<double>(2.11,3.63)<<std::endl;  //double类型
    std::cout<<maxValue<char>('a','b')<<std::endl;      //char类型
    std::cout<<"**************************************"<<std::endl;

    //类模板
    Pair<int,std::string> p1(1,std::string("hello"));
    p1.print();
    Pair<int,double> p2(2,3.3);
    p2.print();
    Pair<std::string,std::string> p3("Hello","World");
    p3.print();
    std::cout<<"**************************************"<<std::endl;

    //固定大小的数组类
    FixedArray<int,5> arr={1,2,3,4,5};
    arr.printf();
    std::cout<<"**************************************"<<std::endl;

    //容器适配器
    std::vector<int>vec={1,2,3,4,5};
    std::list<int>list={30,40,50};

    ContainerPrinter<std::vector,int>vecCon;
    vecCon.print(vec);
    ContainerPrinter<std::list,int>listCon;
    listCon.print(list);
    std::cout<<"**************************************"<<std::endl;
    //折叠变参模板
    printAll(1, 2.5, "Hello", 'A');

    return 0;
}