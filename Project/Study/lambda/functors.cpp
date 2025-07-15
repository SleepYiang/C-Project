#include<iostream>
#include<vector>
#include<algorithm>
struct Adder
{
    int to_add;
    Adder(int value):to_add(value){}
    //重载()运算符号
    int operator()(int x)const
    {
        return to_add+x;
    }
};

//可变累加的仿函数
struct Accumulator
{
    int sum;
    Accumulator():sum(0){}
    //重载()运算符
    void operator()(int x)
    {
        sum+=x;
    }
};

//仿函数的标准库算法
//仿函数：判断一个数是否大于阈值
struct IsGreaterThan
{
    int threshold;
    IsGreaterThan(int value):threshold(value){}
    bool operator()(int x)
    {
        return x>threshold;
    }
};

//仿函数与模板
template<typename T>
struct Compare
{
    bool operator()(const T&a,const T&b)
    {
        return a<b;
    }
};
int main()
{
    //基本仿函数
    Adder add5(5);//创建一个为5的仿函数
    std::cout << "10+5="<<add5(10)<<std::endl;

    std::cout<<"*********************"<<std::endl;

    //可变累加仿函数
    Accumulator add;
    add(10);
    add(20);
    add(30);
    std::cout<<"总和："<<add.sum<<std::endl;//输出总和为60

    std::cout<<"*********************"<<std::endl;

    std::vector<int>numbers={1,2,10,15,20};
    //使用仿函数筛选
    IsGreaterThan GreaterThan10(10);
    auto it=std::find_if(numbers.begin(),numbers.end(),GreaterThan10);
    if (it !=numbers.end())
    {
        std::cout<<"第一个大于10的数"<<*it<<std::endl;
    }else
    {
        std::cout<<"没有找到大于10的数"<<std::endl;
    }

    std::cout<<"*********************"<<std::endl;

    std::vector<int> number = {5, 2, 8, 1, 9};
    // 使用仿函数进行排序
    std::sort(number.begin(), number.end(), Compare<int>());

    std::cout << "排序后的数字: ";
    for(auto num : number) {
        std::cout << num << " "; // 输出: 1 2 5 8 9
    }
    std::cout << std::endl;
    return 0;
}