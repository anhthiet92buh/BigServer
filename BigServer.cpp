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
    Tuioxyz point_M, Pteamplate[100];

    ofstream oxy,f;
    oxy.open("oxyz.vn",ios::app|ios::in);

    //oxy.getloc()

    cout<<"Time: "<<point_M.t<<" IdUser: "<<point_M.user<<" IDValue: "<<point_M.Id<<" Toa do: ("<<point_M.oxyz.x<<","<<point_M.oxyz.y<<","<<point_M.oxyz.z<<")"<<endl;
    cout<<&point_M<<" - "<<endl;
    for (size_t i = 0; i < 100; i++)
    {
        //cout<<i<<endl;
        point_M.Id=i;
        all_point_vn.push_back(point_M);
        // InFileOxyz(&all_point_vn[i],&oxy);
        oxy
    };
    oxy.close();
    // f.open("oxyz.vn");
    // cout<<sizeof(f);
    // f.close();    


    return 0;
}
