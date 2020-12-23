#include <iostream>
#include <fstream>
#include "tuioxyz_struct.h"
#include "save.h"

using namespace std;
int main(int argc, char const *argv[])
{
    fstream f;
    f.open("oxyz.vn",ios::binary|ios::in);

    Tuioxyz a,b;
    for (size_t i = 0; i < 100; i++)
    {
        f.read((char *)&b,sizeof(Tuioxyz));
        InTuioxyz(&b);        
    };

    f.close();
    

    return 0;
}
