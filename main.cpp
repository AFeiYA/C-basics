#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <map>
using namespace std;

struct StudentInfo
{
    int id;
    string name;
};

bool operator==(const StudentInfo & stu1, const StudentInfo & stu2) {
    return stu1.id < stu2.id ;
}

struct StuHash
{
    size_t operator()(StudentInfo const & s) const noexcept
    {
        size_t h1 = hash<int>{}(s.id);
        return h1;
    }
};

struct Student
{
    int score;
    StudentInfo info;
};

typedef unordered_map<StudentInfo, int, StuHash>  MAP_STD;

#define SIZE 5

int main()
{
    MAP_STD mp;
    Student stu;
    Student studends[SIZE] = {
        {100, {21, "Tom"}},
        {90, {23, "Mt"}},
        {100, {22, "Kind"}},
        {110, {24, "Luca"}},
        {101, {25, "Lca"}},
    };

    for (int i = 0; i < SIZE; i++)
    {
        mp.insert(make_pair(studends[i].info, studends[i].score));
    }

    MAP_STD::iterator p;
    for(p=mp.begin();p!=mp.end();++p)
    {
        cout<<"ID:\t"<<p->first.id
        <<"\tname:\t"<<p->first.name
        <<"\tscore:\t"<<p->second<<endl;
    }
}
// vscode gcc result：
// ID:     25      name:   Lca     score:  101
// ID:     24      name:   Luca    score:  110
// ID:     22      name:   Kind    score:  100
// ID:     21      name:   Tom     score:  100
// ID:     23      name:   Mt      score:  90
//visual studio result:
// ID:     21      name:   Tom     score:  100
// ID:     23      name:   Mt      score:  90
// ID:     22      name:   Kind    score:  100
// ID:     24      name:   Luca    score:  110
// ID:     25      name:   Lca     score:  101