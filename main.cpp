#include <iostream>
#include <cstring>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};


struct Student
{
    char name[20];
    unsigned ID;  
    float score;
    Date birthday;
};

main()
{
    Student stu1;
    cout<<stu1.birthday.year<<endl;

    Student stu2 = {"Luca",021,3.5,{2000,9,12}};
    cout<<stu2.birthday.year<<endl;

    Student * pStu2;
    pStu2 = &stu2;
    cout<<pStu2->name<<endl;
    cout<<(*pStu2).name<<endl;

}

