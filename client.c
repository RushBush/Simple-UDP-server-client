#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int fd;
    struct sockaddr_in serv;
    char buf[10]="Hello!";
    socklen_t len=sizeof(serv);

    serv.sin_family=AF_INET;
    serv.sin_port=htons(5555);
    serv.sin_addr.s_addr=inet_addr("127.0.0.1");

    fd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    sendto(fd,&buf,sizeof(buf),MSG_CONFIRM,(struct sockaddr *)&serv,len);

    printf("Send: %s\n",buf);

    recvfrom(fd,&buf,sizeof(buf),MSG_WAITALL,(struct sockaddr *)&serv,&len);

    printf("Receive: %s\n",buf);

    close(fd);

    return 0;
}
