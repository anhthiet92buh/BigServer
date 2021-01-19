#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int sockfd = -1;
    struct sockaddr_in server_addr;
    char recv_buffer[1024]; //Chua data gui qua lai
    time_t ticks;

    memset(recv_buffer,0,sizeof(recv_buffer));  //set lai gia tri
    memset(&server_addr,0,sizeof(server_addr));

    sockfd = socket(AF_INET, SOCKS_STREAM,0);
    server_addr.sin_









    return 0;
}
