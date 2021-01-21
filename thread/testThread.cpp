#include <iostream>
#include <pthread.h>
#include <thread>
#include <stdio.h>
#include <string.h>

using namespace std;

void *my_thread(void *argv){

    printf("Hello World!!! --- %s\n", (char*)argv);
    return argv;
};

int main(int argc, char const *argv[])
{
    pthread_t thread1, thread2;
    char a[100]={0};
    void *t;

    memset(a,0,sizeof(a));
    t=&a[0];

    pthread_create(&thread1,NULL,my_thread,(void*)"Phu");
    pthread_create(&thread2,NULL,my_thread,(void*)"Phong");

    pthread_join(thread1,&t);
    printf("Thread 1 return %s\n",a);
    cout<<a<<endl;
    pthread_join(thread2,&t);
    printf("Thread 2 return %s\n",a);   

    return 0;
}
