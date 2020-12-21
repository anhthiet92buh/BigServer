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
    Tuioxyz point_M, Pteamplate;

    int it;
    fstream oxy,f;
    oxy.open("oxyz.vn");
    // cout<<"Time: "<<point_M.t<<" IdUser: "<<point_M.user<<" IDValue: "<<point_M.Id<<" Toa do: ("<<point_M.oxyz.x<<","<<point_M.oxyz.y<<","<<point_M.oxyz.z<<")"<<endl;
    // cout<<&point_M<<" - "<<endl;
    for (size_t i = 0; i < 100; i++)
    {
        point_M.Id=i;
        all_point_vn.push_back(point_M);  
        InFileOxyz(&point_M,&oxy);      
    };

    oxy.close();
    f.open("oxyz.vn");
    
    while (!f.eof())
    {
        f.read((char*)&it,sizeof(int));
        cout<<it<<endl;
    };
    

    // f.open("oxyz.vn");
    // cout<<sizeof(f);
    f.close();    
    system("pause");

    return 0;
}
