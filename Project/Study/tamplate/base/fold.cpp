#include <iostream>
#include<string>
#include<algorithm>
// 一元折叠
//对每个参数非操作，然后再将这些操作&&
//(!args && ...) 相当于 !a && !b && ...
template <typename ...Args>
bool allNot(const Args&... args)
{
    return (!args &&...);
}
// 二元左折叠：((arg1 + arg2) + arg3) + ... + argN
    //左折叠
template <typename... Args>
auto sumLeftFold(const Args &... args)
{
    return (args + ...); // 左折叠
}
    //右折叠
template <typename... Args>
auto productRightFold(const Args &... args)
{
    return (args * ...);
}
//嵌套折叠
template <typename... Args>
auto complexFold(const Args&... args)
{
    //先左折叠再右折叠，然后求乘积
    return(args+...)*(...+args);
}
//二元操作在这得表达式中的作用
    //逻辑与操作
template<typename... Args>
bool allTrue(const Args&... args)
{
    return(args&&...);
}
   //左移动操作
template<typename...Args>
void printAll(const Args&...args)
{
    (std::cout<<...<<args)<<std::endl;//使用“<<”进行左折叠

}
    //自定义操作符
struct Point
{
    int x;
    int y;
    //重载+运算符
    Point operator+(const Point&other)const
    {
        return Point{x+other.x, y+other.y};
    }
};
//二元左折叠
template<typename...Args>
Point sumPoints(const Args&...args)
{
    return (args+...);
}
//************************Project*************************************//
    //字符串的拼接
template<typename...Args>
std::string concatenate(const Args&...args)
{
    return (std::string{}+...+args);
}
    //计算最大值
template<typename T, typename... Args>
T maxAll(T first, Args... args) {
    return (std::max)(first,( ... , args)); // 左折叠
}
    //筛选逻辑
template<typename...Args>
bool anyTrue(const Args&...args)
{
    return (args ||...);
}

//************************************************************//

int main()
{
    //一元折叠
    std::cout<<allNot(0)<<std::endl;
    std::cout<<"**************************************"<<std::endl;
    //二元折叠(左折叠)
    std::cout << sumLeftFold(1, 2, 3, 4) << std::endl; // 输出：10
    std::cout<<"**************************************"<<std::endl;
    //二元折叠(右折叠)
    std::cout<<productRightFold(1, 2, 3, 4) << std::endl;//输出：24
    std::cout<<"**************************************"<<std::endl;
    //嵌套折叠
    std::cout<<complexFold(1, 2, 3) << std::endl;//输出：36
    std::cout<<"**************************************"<<std::endl;
    //二元折叠表达式的应用
        //逻辑与操作
    std::cout<<std::boolalpha<< std::endl;
    std::cout<<allTrue(true,false,true) << std::endl;//输出：false
    std::cout<<allTrue(true,true,true) << std::endl;//输出：true
    std::cout<<"**************************************"<<std::endl;
        //左移输出
    printAll(1,2,3,"hello"," ""world",'!');
    std::cout<<"**************************************"<<std::endl;
        //自定义操作符
    Point p1{1,2},p2{3,4},p3{5,6};
    Point result=sumPoints(p1,p2,p3);
    std::cout<<"sumPoints: "<<result.x<<" "<<result.y<<std::endl;
    std::cout<<"**************************************"<<std::endl;
    //字符串的拼接
    std::string str=concatenate("hello"," ","World","!","have",'a',"nice","day");
    std::cout<<str<<std::endl;
    std::cout<<"**************************************"<<std::endl;
    //计算最大值
    std::cout<<maxAll(1,3,8,9,2)<< std::endl;
    std::cout<<"**************************************"<<std::endl;
    //筛选逻辑
    std::cout<<anyTrue(false,false,false) << std::endl;
    std::cout<<anyTrue(true,true,true) << std::endl;
    return 0;
}