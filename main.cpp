#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    multiset<int> st;
    int a[10] = {1, 8, 2, 45, 26, 37, 18, 95, 15, 5};
    for (int i = 0; i < 10; i++)
    {
        st.insert(a[i]);
    }
    multiset<int>::iterator i;
    for (i = st.begin(); i != st.end(); i++)
    {
        cout << *i << ",";
    }
    cout << endl;

    i = st.find(45);
    if (i == st.end())
        cout << "not found!" << endl;
    else
        cout << "found 45" << endl;

    i = st.lower_bound(16);
    cout << "16 lower bound is:" << *i << endl;

    i = st.lower_bound(18);
    cout << "18 lower bound is:" << *i << endl;

    i = st.upper_bound(16);
    cout << "16 upper bound is:" << *i << endl;

    i = st.upper_bound(18);
    cout << "18 upper bound is:" << *i << endl;

    return 0;
}
//results:
// 1,2,5,8,15,18,26,37,45,95,
// found 45
// 16 lower bound is:18
// 18 lower bound is:18
// 16 upper bound is:18
// 18 upper bound is:26