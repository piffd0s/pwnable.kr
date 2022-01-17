#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int sd;
    int port;
    int start;
    int end;
    int rval;
    struct hostent *hostaddr;
    struct sockaddr_in servaddr;

    start = 1252;
    end   = 1252;
    for(port = start; port <= end; port++)
    {
        sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sd == -1)
        {
            perror("Socket()\n");
            return (errno);
        }

        memset(&servaddr, 0, sizeof(servaddr));

        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);

        hostaddr = gethostbyname("127.0.0.1");

        memcpy(&servaddr.sin_addr, hostaddr->h_addr, hostaddr->h_length);

        rval = connect(sd, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if(rval == -1)
        {
            printf("Port %d is closed\n", port);
            close(sd);
        }
        else printf("Port %d is open\n", port);

        close(sd);
    }

    return 0;
}