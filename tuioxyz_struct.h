#include<iostream>
#include <time.h>
//bao gom Time: t, ID User: U, ID: i, toa do: oxyz
typedef struct{
    int64_t x=1;
    int64_t y=2;
    int64_t z=3;
}Oxyz;

typedef struct{
    time_t t=0;
    double user=123;
    long double Id;
    Oxyz oxyz;       
}Tuioxyz;