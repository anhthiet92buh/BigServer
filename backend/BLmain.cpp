#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctime>




//..................
#ifdef WIN32
#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#else
#include "/usr/include/postgresql/libpq-fe.h"
#endif

//---------------------------
static char *conninfo =(char*)"host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=11520380 dbname=DB1kytu";
static PGconn *conn;
static PGresult *res;



//..................
static void exit_nicely(PGconn *conn){
    PQfinish(conn);
    //exit(1);
};


//...................
using namespace std;
int main(int argc, char const *argv[])
{
    int listenfd = -1;
    int connfd = -1;
    struct sockaddr_in server_addr;
    char send_buffer[1024];
    time_t ticks;
    int nFields;


    listenfd = socket(AF_INET, SOCK_STREAM,0); //Sever tao socket chuyen nhan(listen) cac ket noi tu client
    server_addr.sin_family = AF_INET;           //Server khoi tao dia chi cho rieng minh
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");   //Server khoi tao dia chi cho rieng minh
    server_addr.sin_port = htons(5000); //Server khoi tao dia chi cho rieng minh

    bind(listenfd, (struct sockaddr *)&server_addr,sizeof(server_addr));    //Dinh kem Ip chinh no vao socket chinh no tao ra
    listen(listenfd,100);//Lang nghe 100 socket client

    //khoi tao ket noi server toi database
    res = PQexec(conn, "SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" = 5;");

    while (1)
    {

        //Xu ly ket noi database






        // if (PQresultStatus(res) != PGRES_TUPLES_OK)
        // {
        //     fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
        //     PQclear(res);
        //     exit_nicely(conn);
        // };
        //
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); //Tao socket cho client
        std::cout<<"Vua khoi tao ket noi Client den Server"<<connfd<<endl;
        ticks = time(NULL);
        sprintf(send_buffer, "Server phan hoi luc %s", ctime(&ticks));
        write(connfd, send_buffer, strlen(send_buffer));
        
        //close(connfd);
    };
    
    PQclear(res);
    close(connfd);



    return 0;
}
