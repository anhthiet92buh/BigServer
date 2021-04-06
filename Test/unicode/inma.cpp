#include <iostream>
#include <cwchar>

using namespace std;
int main(int argc, char const *argv[])
{
    wchar_t x[100],y[100];
    wint_t z=500;
    wcout<<"Kiểm tra in mã Wchar: "<<z<<endl;
    wcout<<"In Thử sizeof(): "<<sizeof(z)<<endl;

    return 0;
}
