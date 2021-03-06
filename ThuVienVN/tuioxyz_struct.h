#ifndef TUIOXYZ_STRUCT_H
#define TUIOXYZ_STRUCT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include    <iostream>
#include    <time.h>
#include    <vector>
//bao gom Time: t, ID User: U, ID: i, toa do: oxyz
typedef struct Oxyz {
    int64_t x=0;
    int64_t y=0;
    int64_t z=0;
};

typedef struct Tuioxyz  {
    time_t t=0;
    double user=0;
    long double Id=0;
    Oxyz oxyz;       
};

typedef struct PointVN  {
    long double allPoint=0;
    Tuioxyz ValuePoint;

};


typedef struct len  {
    long double len=0;
    PointVN onePointVN;
};

typedef struct lenOfPointVN {
    PointVN PointVN_Goc;
    long double lens[];
    vector<Oxyz> lensOxyz; 
};

typedef struct oxyz1c
{
    int64_t id_Logic;
    char value;
    int64_t x;
    int64_t y;
    int64_t z;
};

#ifdef __cplusplus
}
#endif


#endif