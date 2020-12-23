#include <iostream>
#include <fstream>
#include "tuioxyz_struct.h"

using namespace std;
int main(int argc, char const *argv[])
{
    fstream f;
    f.open("oxyz.vn",ios::binary|ios::out);

    Tuioxyz a,b;
    for (size_t i = 0; i < 100; i++)
    {
        a.Id=i;
        f.write((char*)&a,sizeof(Tuioxyz));
    };

    f.close();
    

    return 0;
}
