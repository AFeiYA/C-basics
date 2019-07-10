#include <iostream>
#include <map>
using namespace std;

struct StudentInfo
{
    int id;
    char name[20];
};
struct Student
{
    int score;
    StudentInfo info;
};

typedef multimap<int, StudentInfo> MAP_STD;

#define SIZE 5

int main()
{
    MAP_STD mp;
    Student stu;
    Student studends[SIZE] = {
        {100, {21, "Tom"}},
        {90, {22, "Mt"}},
        {100, {23, "Kind"}},
        {110, {21, "Luca"}},
        {101, {21, "Lca"}},
    };

    for (int i = 0; i < SIZE; i++)
    {
        mp.insert(make_pair(studends[i].score, studends[i].info));
    }
    char cmd[20];
    while (cin >> cmd)
    {
        if (cmd[0] == 'A')
        {
            cout << "add:id name scoure:" << endl;
            cin >> stu.info.id >> stu.info.name >> stu.score;
            mp.insert(make_pair(stu.score, stu.info));
        }
        else if (cmd[0] == 'Q')
        {
            int score;
            cout << "query:scoure:" << endl;
            cin >> score;
            MAP_STD::iterator p = mp.lower_bound(score);
            MAP_STD::iterator q = mp.upper_bound(score);
            if (q == mp.end())
            {
                --q;
                cout<<"Here is the highest score:"<<endl;
                cout << q->second.name << ":\t" << q->first << endl;
            }

            else
            {
                if (p != mp.begin())
                {
                    if (p->first != score)
                    {
                        --p;
                        cout << p->second.name << ":\t" << p->first << endl;
                    }
                    else if (p->first == score)
                    {
                        for (; p != mp.begin() && p->first == score; --p)
                        {
                        }
                        if (p->first != score)
                        {
                            cout << p->second.name << ":\t" << p->first << endl;
                        }
                        else
                        {
                            cout << "Nobody under :" << score << endl;
                        }
                    }
                }
                else
                {
                    cout << "Nobody under :" << score << endl;
                }
            }
        }
    }
}