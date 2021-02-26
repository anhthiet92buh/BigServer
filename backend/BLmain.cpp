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
#include <wchar.h>
//...........
#define __STDC_FORMAT_MACROS 1
#include <inttypes.h>

// #include <stdio.h>
#include <unicode/utypes.h>
#include <unicode/uchar.h>
#include <unicode/locid.h>
#include <unicode/ustring.h>
#include <unicode/ucnv.h>
#include <unicode/unistr.h>
#include <unicode/putil.h>
//...........


using namespace std;
using namespace icu;


#ifndef UPRV_LENGTHOF
#define UPRV_LENGTHOF(array) (int32_t)(sizeof(array)/sizeof((array)[0]))
#endif


//..................
#ifdef WIN32
#include "C:\Program Files\PostgreSQL\13\include\libpq-fe.h"
#else
#include "/usr/include/postgresql/libpq-fe.h"
#endif

//---------------------------
// static char *conninfo =(char*)"host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=123 dbname=DB1kytu";
const char *conninfo = "host=postgres hostaddr=127.0.0.1 port=7532 user=postgres password=123 dbname=DB1kytu";
static PGconn *conn;
static PGresult *res;



//..................
static void exit_nicely(PGconn *conn){
    PQfinish(conn);
    //exit(1);
};


//...................
int main(int argc, char const *argv[])
{
    int listenfd = -1, cout=0;
    int connfd = -1;
    struct sockaddr_in server_addr;
    // string *send_buffer = new string[100];
    // string *sends= new string[500];
    char send_buffer[100];
    char sends[500];
    char send_saukhinoi[700];
    //char *queryt = (char*)"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" = 5;";
    

    time_t ticks;
    int nFields;
    char query[5000];


    listenfd = socket(AF_INET, SOCK_STREAM,0); //Sever tao socket chuyen nhan(listen) cac ket noi tu client
    server_addr.sin_family = AF_INET;           //Server khoi tao dia chi cho rieng minh
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");   //Server khoi tao dia chi cho rieng minh
    server_addr.sin_port = htons(5000); //Server khoi tao dia chi cho rieng minh

    bind(listenfd, (struct sockaddr *)&server_addr,sizeof(server_addr));    //Dinh kem Ip chinh no vao socket chinh no tao ra
    listen(listenfd,1000);//Lang nghe 1000 socket client

    //khoi tao ket noi server toi database
    conn = PQconnectdb(conninfo);
    
    while (1)
    {
        // memset(send_buffer,NULL,sizeof(send_buffer));
        // sends->erase();
        // send_buffer->erase();
        memset(send_buffer,0,sizeof(send_buffer));
        memset(sends,0,sizeof(sends));
        memset(send_saukhinoi,0,sizeof(send_saukhinoi));
        
        
        //Xu ly ket noi client;
        printf("Bat dau accept: \n");
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); //Tao socket cho client
        // sends = (char*)"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" =";
        // sprintf(sends,"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" =");
        sprintf(sends,"SELECT \"id_Logic\", value, x, y, z FROM public.oxyz1c where \"id_Logic\" ='");
        printf("Sends: %s - voi do dai: %ld",sends,sizeof(sends));
        // std::cout<<"Vua khoi tao ket noi Client den Server "<<connfd<<endl;
        // ticks = time(NULL);
        // sprintf(send_buffer, "Server phan hoi luc %s", ctime(&ticks));
        // write(connfd, send_buffer, strlen(send_buffer));
        //send(connfd,"Sever send to Client",21,0);
        // memset(send_buffer,NULL,sizeof(send_buffer));
        read(connfd,send_buffer,100);
        // sends.append(send_buffer).append(";");
        strcpy(send_saukhinoi,sends);
        int count=0;
        while((int)send_buffer[count]!=10) count++;
        send_buffer[count]=0;
        strcat(send_saukhinoi,send_buffer);


        strcat(send_saukhinoi,"';");
        printf("\nChuoi sau khi noi: %s\n",send_saukhinoi);
        // printf("In tung ky tu: ");
        // for (size_t i = 0; i < 700; i++)
        // {
        //     printf("%d",(int)send_saukhinoi[i]);
        // };
        // printf("\n");
        
        
        
        // res = PQexec(conn,(char*)&sends);

        std::cout<<"\nGia tri send_buff tu client: "<<endl;
        std::cout<<sizeof(send_buffer)<<endl;
        // for (size_t i = 0; i < 100; i++)
        // {
        //     std::cout<<send_buffer[i]<<endl;
        // }
        std::cout<<(char*)"So ky tu cua send_buffer: "<<count<<endl;
        //sends->append(send_buffer).append(";");
        //std::cout<<*sends<<endl;



        res=PQexec(conn,send_saukhinoi);
        if (PQresultStatus(res) != PGRES_TUPLES_OK)
        {
            fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
            PQclear(res);
            exit_nicely(conn);
        };
        nFields = PQnfields(res);
        printf("In nFields: %d\n",nFields);
        for (int i = 0; i < nFields; i++)
            printf("%-15s", PQfname(res, i));
        printf("\n\n");
        printf("PQtuples = %d\n",PQntuples(res));
        for (int i = 0; i < PQntuples(res); i++)
        {
            for (int j = 0; j < nFields; j++)
                printf("%-15s", PQgetvalue(res, i, j));
            printf("i = %d\n",i);
        };


        printf("Kiem tra byte tren du lieu: \n");
        char xchar[100];
        UChar uchar_test[100];
        // xchar = *PQgetvalue(res,0,1);
        u_charsToUChars(PQgetvalue(res,0,1),uchar_test,sizeof(*PQgetvalue(res,0,1))); /* include the terminating NUL */
        u_UCharsToChars(uchar_test,xchar,sizeof(uchar_test));
        printf("Byte cua xchar: %s      -sizeof(xchar): ",xchar); std::cout<<sizeof(xchar)<<endl;
        printf("Byte cua int PQgetvalue(res,0,1): "); std::cout<<sizeof(PQgetvalue(res,0,1))<<endl;

        printf("in xchar: ");
        // printf("%X\n",xchar);
        PQclear(res);





        sleep(1);
                
        close(connfd);
        
    };
    
    PQclear(res);

    // delete sends;
    // delete send_buffer;
    return 0;
}
