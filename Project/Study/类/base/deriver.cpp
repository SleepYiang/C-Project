#include <iostream>
//继承
class Animal
{
public:
    void eat() const
    {
        std::cout << "Animal eats." << std::endl;
    }
protected:
    int age;
};
// 派生类
class Dog : public Animal
{
public:
    void bark() const
    {
        std::cout << "Dog barks." << std::endl;
    }
    void setAge(int a)
    {
        age = a; // 访问受保护成员
    }
    int getAge() const
    {
        return age;
    }
};

//多态
class Shape
{
public:
    virtual void draw() const
    {
        // 虚函数
        std::cout << "Drawing a shape." << std::endl;
    }
    virtual ~Shape()
    {
    } // 虚析构函数
};
class Circle : public Shape
{
public:
    void draw() const override
    {
        // 重写虚函数
        std::cout << "Drawing a circle." << std::endl;
    }
};
class Square : public Shape
{
public:
    void draw() const override
    {
        // 重写虚函数
        std::cout << "Drawing a square." << std::endl;
    }
};
void render(const Shape& shape)
{
    shape.draw(); // 动态绑定，根据实际对象类型调用对应的draw()
}
int main()
{
    //继承
    Dog myDog;
    myDog.eat(); // 继承自Animal
    myDog.bark(); // Dog特有
    myDog.setAge(5);
    std::cout << "Dog's age: " << myDog.getAge() << std::endl;

    std::cout << "*******************************" << std::endl;

    //多态
    Circle c;
    Square s;
    Shape genericShape;
    render(c); // 输出: Drawing a circle.
    render(s); // 输出: Drawing a square.
    render(genericShape); // 输出: Drawing a shape.
    return 0;
}