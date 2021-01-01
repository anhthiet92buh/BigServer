#ifndef TUIOXYZ_STRUCT_H
#define TUIOXYZ_STRUCT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include    <iostream>
#include    <time.h>
//bao gom Time: t, ID User: U, ID: i, toa do: oxyz
typedef struct Oxyz{
    int64_t x=0;
    int64_t y=0;
    int64_t z=0;
};

typedef struct Tuioxyz{
    time_t t=0;
    double user=0;
    long double Id=0;
    Oxyz oxyz;       
};

typedef struct PointVN{
    long double allPoint=0;
    Tuioxyz ValuePoint;

};


typedef struct lens{
    long double len=0;
    PointVN
};

#ifdef __cplusplus
}
#endif


#endif