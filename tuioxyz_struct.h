#include<iostream>
#include <time.h>
//bao gom Time: t, ID User: U, ID: i, toa do: oxyz
typedef struct{
    int64_t x;
    int64_t y;
    int64_t z;
}Oxyz;

typedef struct{
    time_t t;
    double user;
    long double Id;
    Oxyz oxyz;       
}Tuioxyz;