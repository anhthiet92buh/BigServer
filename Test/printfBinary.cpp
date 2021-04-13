#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int64_t x,y,z;
    printf("Nhap vao x: ");
    scanf("%ld",&x);

    y=sizeof(x);
    printf("Gia tri sizeof(x):  %ld\n",y);

    printf("Printf Binary:  ");
    for (int64_t i = y*8-1; i >=0; i--)
    {
        z=x>>i;
        if (z&1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        };
        
    };
    printf("\n");
    return 0;
}
