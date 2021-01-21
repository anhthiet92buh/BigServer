#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int pidCon=-1;
    cout<<"The first ID in Program: "<<pidCon<<"  ID getpid: "<<getpid()<<"   ID getppid: "<<getppid()<<endl;
    pidCon = fork();
    if (pidCon)
    {
        cout<<"If truoc - La chuong trinh goc"<<endl;//Chuong trinh cu, pidCon = pid chuong trinh moi
        sleep(10);
        cout<<"ID in Program: "<<pidCon<<"  ID getpid: "<<getpid()<<"   ID getppid: "<<getppid()<<endl;
    }else
    {
        cout<<"Sau Else - La chuong trinh moi nhan ban tu chuong trinh goc"<<endl;//Chuong trinh moi pidCon = 0
        cout<<"ID in Program: "<<pidCon<<"  ID getpid: "<<getpid()<<"   ID getppid: "<<getppid()<<endl;
    };
    
    /*while (1)
    {
        cout<<"ID in Program: "<<pidCon<<"  ID getpid: "<<getpid()<<"   ID getppid: "<<getppid()<<endl;
        sleep(2);  
    };*/
    cout<<"Chuan bi ket thuc chuong trinh"<<endl;

    return 0;
}
