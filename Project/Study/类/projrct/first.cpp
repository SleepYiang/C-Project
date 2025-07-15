#include<iostream>
class Person
{
public:
   Person(const std::string & str,int age):name(str),age(age){}
   void displayInfo()
   {
      std::cout<<"姓名:"<<name<<"年龄:"<<age<<std::endl;
   }
private:
   std::string name;
   int age;
};
class Student:public Person
{
   public:
   Student(const std::string & str,int age,int ID):Person(str,age),studentId(ID){}
   void displayInfo()
   {
      Person::displayInfo();
      std::cout<<"studentId:"<<studentId<<std::endl;
   }
private:
   int studentId;
};
int main()
{
   Student stu("Alice", 20, 12345);
   stu.displayInfo();
   return 0;
}