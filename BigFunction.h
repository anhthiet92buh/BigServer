#include <iostream>
#include <vector>
using namespace std;
struct Point{
    tm                      time_point;
    vector<long double>     vector_Point;
};

struct Line{
    time_t  t_line;
    Point   PointA;
    Point   PointB;
    vector<long double> VectorLine;
};

struct Value{
    time_t t_Value;
    string s_Value;

};

struct ID{
    time_t      t_ID;
    long double id;
};

struct BigFunction
{
    time_t  time_BigFunction;
    Point   point;
    Line    line;
    Value   value;
    ID      id;
};
