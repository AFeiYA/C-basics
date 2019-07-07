#include <iostream>
#include <cstring>
using namespace std;

main()
{

    //
    char ch1[20] = "abcde";
    //ch1 value to *pc1
    char *pc1 = ch1;

    cout<<"ch1 started address : "<<&ch1<<endl;
    cout<<"pc1's address       : "<<&pc1<<endl;


    ++pc1;
    cout<<"next value of pc1   : "<<pc1<<endl;
    cout<<"pc1's address       : "<<&pc1<<endl;
    cout<<"ch1's address       : "<<&ch1<<endl;

    ++pc1;
    cout<<"next value of pc1   : "<<pc1<<endl;
    cout<<"pc1's address       : "<<&pc1<<endl;
    cout<<"ch1's address       : "<<&ch1<<endl;

    cout<<"next value of ch1   : "<<ch1<<endl;
    cout<<"next value of pc1   : "<<pc1<<endl;

    cout<<"original ch1 of ch1 : "<<ch1<<endl;

    *pc1='m';
    
    cout<<"modified ch1 of ch1 : "<<ch1<<endl;
    cout<<"the value of pc1    : "<<pc1<<endl;

    cout<<"the size of pc1     : "<<sizeof(ch1)<<endl;
    cout<<"the size of pc1     : "<<sizeof(pc1)<<endl;

    for(int i=0; ch1[i]; i++)
    {
        cout<<ch1[i]<<endl;
    }

}

