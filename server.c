#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int fd;
    struct sockaddr_in serv,cl;
    socklen_t len=sizeof(cl);
    char buf[10];

    serv.sin_family=AF_INET;
    serv.sin_port=htons(5555);
    serv.sin_addr.s_addr=inet_addr("127.0.0.1");

    fd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    bind(fd,(struct sockaddr *)&serv,sizeof(serv));


    recvfrom(fd,&buf,sizeof(buf),0,(struct sockaddr *)&cl,&len);

    printf("Receive: %s\n",buf);

    buf[0]='7';

    sendto(fd,&buf,sizeof(buf),0,(struct sockaddr *)&cl,len);
    printf("Send: %s\n",buf);

    close(fd);

    return 0;
}
