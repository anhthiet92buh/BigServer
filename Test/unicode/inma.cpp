#include <iostream>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

using namespace std;
int main(int argc, char const *argv[])
{
     
    char t[10];
    wchar_t 
    // cin>>t;
    // scanf(t);
    memset(t,0,10);
    fgets(t,10,stdin);
    cout<<t<<endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout<<i<<"      "<<(int)t[i]<<endl;
    };
    

    return 0;
}
