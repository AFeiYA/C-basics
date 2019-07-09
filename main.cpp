#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char name[20];
    int id;
    float gpa;
};

///选择排序
void SelectionSort(int a[], int size)
{

    for (int i = 0; i < size - 1; ++i)
    {
        int minElementIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (a[minElementIndex] > a[j])
            {
                minElementIndex = j;
            }
        }
        int temp = a[i];
        a[i] = a[minElementIndex];
        a[minElementIndex] = temp;
    }
}
/// 二分查找求方程f(x)=x^3-5x^2+10x-80 = 0的根m, |f(m)|<=10^-6 :f(x)单调递增。
double f(double x) { return x * x * x - 5 * x * x + 10 * x - 80; }
double findRoot(double x1, double x2, double EPS)
{
    double root, y;
    root = x1 + (x2 - x1) / 2;
    int triedTimes = 1;
    y = f(root);

    while (abs(y) > EPS)
    {
        if (y > 0)
            x2 = root;
        else
            x1 = root;
        root = x1 + (x2 - x1) / 2;
        y = f(root);
        triedTimes++;
    }
    cout << triedTimes << endl;
    return root;
}
//stl 初步
///sort rules
bool SortByStuId(Student s1, Student s2)
{
    return s1.id < s2.id;
}
bool SortByStuGpa(Student s1, Student s2)
{
    return s1.gpa > s2.gpa;
}
bool SortByStuName(Student s1, Student s2)
{
    if (strcmp(s1.name, s2.name)<0){
        return true;
    }
    return false;
}


void PrintStudentInfo(Student stu)
{
    cout<<"{"<<stu.name<<","<<stu.id<<","<<stu.gpa<<"},";
}
void PrintStudentsArray(Student students[], int size){
    cout<<"{";
    for(int i=0; i<size;i++)
    {
        PrintStudentInfo(students[i]);
    }
    cout<<"}"<<endl;
}


int main()
{

    Student students[] = {{"Luca",2018021,3.5},{"AFeiYA",2018029,3.6},{"Kinder",2018001,2.5},};
   
    cout<<"original order:\t";
    PrintStudentsArray(students, 3);

    cout<<"SortByStuId:\t";
    sort(students, students+3, SortByStuId);  
    PrintStudentsArray(students, 3);

    cout<<"SortByStuGPA:\t";
    sort(students, students+3, SortByStuGpa);
    PrintStudentsArray(students, 3);

    cout<<"SortByStuName:\t";
    sort(students, students+3, SortByStuName);
    PrintStudentsArray(students, 3);

    return 0;
}
