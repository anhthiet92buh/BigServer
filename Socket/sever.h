#ifndef SEVER_H
#define SEVER_H

// #ifdef __cplusplus
// extern "C"
// {
// #endif


#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include "../database/database.h"

int sever()
{
    int listenfd = -1;
    int connfd = -1;
    struct sockaddr_in server_addr;
    oxyz1c *ketqua;
    time_t ticks;

    // memset(send_buffer,0,sizeof(send_buffer));  //set lai gia tri
    // memset(&server_addr,0,sizeof(server_addr));
    PQclear(res);

    listenfd = socket(AF_INET, SOCK_STREAM,0); //Sever tao socket chuyen nhan(listen) cac ket noi tu client
    server_addr.sin_family = AF_INET;           //Server khoi tao dia chi cho rieng minh
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");   //Server khoi tao dia chi cho rieng minh
    server_addr.sin_port = htons(5000); //Server khoi tao dia chi cho rieng minh

    bind(listenfd, (struct sockaddr *)&server_addr,sizeof(server_addr));    //Dinh kem Ip chinh no vao socket chinh no tao ra
    listen(listenfd,100);//Lang nghe 100 socket client

    while (1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        std::cout<<"Vua khoi tao ket noi Client den Server";
        ticks = time(NULL);
        sprintf((char*)ketqua,(char*)getOneChar(conninfo));
        write(connfd, ketqua,-1);
        // sprintf(send_buffer,"Ban vua ket noi xong");
        // write(connfd, send_buffer, strlen(send_buffer));
        //close(connfd);
        PQclear(res);
        PQfinish(conn);
    };
    


    return 0;
}






// #ifdef __cplusplus
// }
// #endif


#endif