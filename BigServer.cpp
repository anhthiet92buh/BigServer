#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "BigFunction.h"
#include "tuioxyz_struct.h"
#include "save.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Tuioxyz *pp, *pt, point_M, Pteamplate;
    pp=&point_M;
    pt=&Pteamplate;
    int it;
    fstream oxy,f;
    oxy.open("oxyz.vn",ios::app|ios::binary);
    // cout<<"Time: "<<point_M.t<<" IdUser: "<<point_M.user<<" IDValue: "<<point_M.Id<<" Toa do: ("<<point_M.oxyz.x<<","<<point_M.oxyz.y<<","<<point_M.oxyz.z<<")"<<endl;
    // cout<<&point_M<<" - "<<endl;
    for (size_t i = 0; i < 100; i++)
    {   
        pp->Id=i;
        cout<<point_M.Id<<endl;
        InFileOxyz(pp,&oxy);
    };


    oxy.close();

    f.open("oxyz.vn",ios::in|ios::binary);
    for (size_t i = 0; i < 50; i++)
    {
        f.read((char*)&Pteamplate,sizeof(Tuioxyz));
        InTuioxyz(&Pteamplate);
    };

    f.close();




    // f.read((char*)&Pteamplate,sizeof(Pteamplate));

    // for (size_t i = 0; i < 100; i++)
    // {
    //     Pteamplate= f.seekg(i)
    //     InTuioxyz(&Pteamplate);        
    // };
    // f.close();


    // f.open("oxyz.vn");
    
    // while (!f.eof())
    // {
    //     ReadFileOxyz(pt,&f);
    //     InTuioxyz(pt);
    // };
    

    // // f.open("oxyz.vn");
    // // cout<<sizeof(f);
    // f.close();    
    // system("pause");

    return 0;
}
