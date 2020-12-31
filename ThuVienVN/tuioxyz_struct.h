#ifndef TUIOXYZ_STRUCT_H
#define TUIOXYZ_STRUCT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include    <iostream>
#include    <time.h>
//bao gom Time: t, ID User: U, ID: i, toa do: oxyz
typedef struct{
    int64_t x=0;
    int64_t y=0;
    int64_t z=0;
}Oxyz;

typedef struct{
    time_t t=0;
    double user=0;
    long double Id=0;
    Oxyz oxyz;       
}Tuioxyz;

typedef struct
{
    long double allPoint=0;
    Tuioxyz ValuePoint;

}PointVN;

typedef struct {
    long double len=0;
    Tuioxyz 


}lens;

#ifdef __cplusplus
}
#endif


#endif