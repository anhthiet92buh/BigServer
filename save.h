#include <iostream>
#include <fstream>
using namespace std;
void InFileOxyz(Tuioxyz *t,fstream *oxy){
    // oxy->open("oxyz.vn",ios::app);
    oxy->write((char*) t,sizeof(Tuioxyz));
    };

void ReadFileOxyz(Tuioxyz *t, fstream *oxy){
    oxy->read((char*)t,sizeof(Tuioxyz));
};

void InTuioxyz(Tuioxyz *t){
    cout<<t->t<<"   "<<t->user<<"   "<<t->Id<<" ("<<t->oxyz.x<<","<<t->oxyz.y<<","<<t->oxyz.z<<")"<<endl;

};










    
    

    
