#include <iostream>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <unicode/ustdio.h>
#include <unicode/ustring.h>
#include <unicode/utf32.h>
#include <unicode/utf_old.h>
#include <locale.h>

using namespace std;
int main(int argc, char const *argv[])
{
     
    // UChar32 *t;
    char *locale;
    locale = setlocale(LC_ALL,"");

    // wstring t=L"Tiếng Việt";
    // wcout<<t<<endl;
    // char a=(char)"asdk wdf";
    for (size_t i = 0; i < 1000; i++)
    {
        cout<<hex<<i<<"       ";
        cout<<u_char(i)<<"        ";
        cout<<char(i)<<endl;
    };
    
    

    return 0;
}
