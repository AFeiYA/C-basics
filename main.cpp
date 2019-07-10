#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

# define NUM 6

int main()
{
    //char a[NUM] = {'a', 'b', 'c', 'd','f'};
    char a[NUM] = "abcdf";
    char b[NUM] = "adbgd";
    char *p = a;
    do{
        cout<<p<<endl;
    }while (next_permutation(a, a+NUM-1));

    a[3]='f';
    cout<<p<<endl;
    set<char> st;
    for(int i=0; i<NUM-1;++i)
    {
        auto result = st.insert(a[i]);
        if(!result.second)
        {
            cout<<*result.first<<" already in list."<<endl;
        }
        else
        {
            cout<<*result.first<<" added."<<endl;
        }
        
    }
    set<char>::iterator i;
    for(i=st.begin(); i!=st.end();++i)
    {
        cout<<*i<<",";
    }


    cout<<endl;

}
