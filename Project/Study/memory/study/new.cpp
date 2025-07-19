#include<iostream>

//使用new操作符
class MyClass
{
public:
    MyClass(int val):value(val)
    {
        std::cout<<"Constructor called with value: "<<value<<std::endl;
    }
    ~MyClass()
    {
        std::cout<<"Destructor called with valueL: "<<value<<std::endl;
    }
    int value;
};
int main()
{
    //使用malloc分配一个int内存
    int* p=(int*)malloc(sizeof(int));
    if (p==nullptr)
    {
        std::cout<<"memory allocation failed"<<std::endl;
        return -1;
    }
    *p=42;
    std::cout<<"value: "<<*p<<std::endl;
    //释放内存
    free(p);
    std::cout<<"**************************************"<<std::endl;
    //使用new开辟内存
    MyClass* obj=new MyClass(10);
    std::cout<<"object value"<<obj->value<<std::endl;
    //释放并且析构内存
    delete obj;
    std::cout<<"**************************************"<<std::endl;
    //使用new创建数组
    int * arr=new int[5];
    for(int i=0;i<5;i++)
    {
        arr[i]=i*10;
    }
    for(int i=0;i<5;i++)
    {
        std::cout<<arr[i]<<std::endl;
    }
    //释放数组的内存
    delete[] arr;
    std::cout<<"**************************************"<<std::endl;
    //异常安全（防止new抛出异常，改为nullptr）
    int *p1=new(std::nothrow) int;
    if (p1==nullptr)
    {
        std::cerr<<"Memory allocation failed"<<std::endl;
        return 1;
    }
    *p1=100;
    std::cout<<"value: "<<*p1<<std::endl;
    delete p1;

    return 0;
}
