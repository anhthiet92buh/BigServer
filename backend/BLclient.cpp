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
#include <iostream>
#include <istream>

using namespace std;

int main(int argc, char const *argv[])
{
    int sockfd = -1, connect_sv;
    struct sockaddr_in server_addr;
    char recv_buffer[5000]; //Chua data gui qua lai
    char recv;
    time_t ticks;
    char query[50];
    // char query[] = "Nguyễn Anh Thiết";

    memset(recv_buffer,0,sizeof(recv_buffer));  //set lai gia tri
    memset(&server_addr,0,sizeof(server_addr));

    sockfd = socket(AF_INET, SOCK_STREAM,0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(5000);

    while(connect(sockfd,(struct sockaddr *)&server_addr, sizeof(server_addr))==0)
    {
        //connect_sv = connect(sockfd,(struct sockaddr *)&server_addr, sizeof(server_addr)); //connect to sever
        // cout<<"Gia tri connect: "<<connect_sv<<endl;
        memset(query,0,sizeof(query));
        
        fgets(query,50,stdin);
        // cin>>query;
        // cout<<query<<endl;
        // for (size_t i = 0; i < 50; i++)
        // {
        //     cout<<(int)query[i]<<endl;
        // };
        
        // read(sockfd, recv_buffer,sizeof(recv_buffer)); //doc du lieu tu sever
        // printf("\n%s\n",recv_buffer);
        //close(sockfd);
        send(sockfd,query,50,0);

        // read(sockfd, recv_buffer,sizeof(recv_buffer));
        // printf("\n%s\n",recv_buffer);
        // cin>>recv_buffer;
        // send(sockfd,recv_buffer,sizeof(recv_buffer),0);

        // memset(recv_buffer,0,sizeof(recv_buffer));  //set lai gia tri

        sleep(1);
        close(sockfd); 
    };

    return 0;
}
