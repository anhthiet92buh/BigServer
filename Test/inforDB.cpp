#include<iostream>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[])
{
    ofstream t;
    t.open("intchar.txt",ios::out);
    for (size_t i = 3; i <= 95; i++)
    {
        t<<i<<" "<<char(i+31)<<endl;
    };
    t.close();
    
    return 0;
}
