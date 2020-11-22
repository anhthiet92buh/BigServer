#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <bitset>
using namespace std;

union Test
    {
        double x;
        double y;
        float s;
    };

int main(int argc, char *argv[])
{
    Test t;
    t.x = 25.156546;
    cout << t.x << endl;
    t.y = 35489;
    cout<< t.y << endl;
    t.s = 156865;
    cout<<t.s<<endl;

    cout<<"Test xem bo nho" <<endl;
    cout <<t.x<<endl;
    cout<<t.y<<endl;
    cout<<t.s<<endl;
    cout<<"Bat dau bitset"<<endl;

    bitset<10> bitst;
    //bitst[0]="asjdhkjaef";
    //bitst[1]=1000;
    //bitst[2]=2314866;
    //bitst[3]=2.569;
    bitst = "k";

    cout << bitst[0] <<endl;

    cout << bitst <<endl<<endl<<endl<<endl;

    return 0;
}
