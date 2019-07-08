#include <iostream>
#include <cstring>
using namespace std;



main()
{
    char s1[100] = "1234567";
    char s2[100] = "abcdefg";
    char s3[100] = "AFCD";
    strcat(s1, s2);
    cout<<s1<<endl;
    strncat(s1, s2, 5);
    cout<<s1<<endl;
    strncpy(s1,s3,4);
    cout<<s1<<endl;
    strncpy(s1,s3,5);
    cout<<s1<<endl;
    char *p = strchr(s1, 'C');

    cout<<&p<<endl;
    if(p){
        cout<<p-s1<<*p<<endl;
    }
    else{
        cout<<*p<<endl;
    }

    p=strstr(s1, "FC");

    cout<<&p<<endl;
    if(p){
        cout<<p-s1<<p<<endl;
    }
    else{
        cout<<*p<<endl;
    }

    char str1[] = "=This---is =,a ---test string for strtok,-go-!";
    p = strtok(str1, " =,!-");
    cout<<"p's value:"<<p<<",\t"<<"Str1's value:"<<str1<<endl;
    p = strtok(NULL, " =,!-");
    cout<<"p's value:"<<p<<",\t"<<"Str1's value:"<<str1<<endl;


    int i=0;
    while(p){
        cout<<p<<" ";
        i++;
        p = strtok(NULL, " =,!-");
    }
    cout<<"!"<<endl;





}

