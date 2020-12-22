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
    vector<Tuioxyz> all_point_vn;
    Tuioxyz *pp, *pt, point_M, Pteamplate;
    pp=&point_M;
    pt=&Pteamplate;
    int it;
    fstream oxy,f;
    oxy.open("oxyz.vn",ios::app);
    // cout<<"Time: "<<point_M.t<<" IdUser: "<<point_M.user<<" IDValue: "<<point_M.Id<<" Toa do: ("<<point_M.oxyz.x<<","<<point_M.oxyz.y<<","<<point_M.oxyz.z<<")"<<endl;
    // cout<<&point_M<<" - "<<endl;
    for (size_t i = 0; i < 1000; i++)
    {
        pp->Id=i;
        cout<<point_M.Id<<endl;
        all_point_vn.push_back(*pp);  
        InFileOxyz(pp,&oxy);      
    };

    // InTuioxyz(pp);

    oxy.close();
    f.open("oxyz.vn");
    
    while (!f.eof())
    {
        ReadFileOxyz(pt,&f);
        InTuioxyz(pt);
    };
    

    // f.open("oxyz.vn");
    // cout<<sizeof(f);
    f.close();    
    system("pause");

    return 0;
}
