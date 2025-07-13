#include <iostream>
#include<cstring>
class Mystring {
public:
    //默认构造
    Mystring():data(nullptr){}
    //有参构造函数
    Mystring(const char* str)
    {
        if (str)
        {
            data=new char[strlen(str)+1];
            strcpy(data,str);//复制
        }else
        {
            data=nullptr;
        }
    }
    //拷贝构造
    Mystring(const Mystring& other)
    {
        if (other.data)
        {
            data=new char[strlen(other.data)+1];
            strcpy(data,other.data);
        }else
        {
            data=nullptr;
        }
    }
    //拷贝赋值构造
    Mystring&operator=(const Mystring& other)
    {
        if (this!=&other)
        {
            data=new char[strlen(other.data)+1];
        }else
        {
            data=nullptr;
        }
        return *this;
    }
    //移动赋值构造禁用
    Mystring&operator=(Mystring&&other)=delete;
    //移动构造禁用
    Mystring(Mystring&&other)=default;
    //重载比较运算符
    bool operator==(const Mystring &other) const
    {
        if (data==nullptr&&other.data==nullptr) return true;
        if (data==nullptr||other.data==nullptr) return false;
        return strcmp(other.data,data)==0;//比较运算
    }
    //重载输出运算符
    friend std::ostream& operator<< (std::ostream&os,const Mystring &myStr)
    {
        if (myStr.data)
        {
            os<<myStr.data;
        }
        return os;
    }
    ~Mystring()
    {
        delete[] data;
    }
private:
    char*data;
};
int main()
{
    Mystring str1("hello world");
    std::cout<<"str1"<<str1<<std::endl;
}