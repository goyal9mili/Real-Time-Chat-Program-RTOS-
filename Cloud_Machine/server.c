#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 43141

int main(){
    int sd, new_sd;
    struct sockaddr_in serv, cli;
    char buffer[1024];

    sd = socket(AF_INET, SOCK_STREAM, 0);

    // Creating socket file descriptor
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(PORT);

    bind(sd, (struct sockaddr *)(&serv), sizeof(serv));
    listen(sd, 5);
    printf("The server is ready to listen from the client\n");
    int sz = sizeof(cli);
    new_sd = accept(sd, (struct sockaddr *)&cli, (socklen_t*)&sz);
    int n = 5;
    while(n)
    {
      read(new_sd, buffer, sizeof(buffer));
      printf("The data read is : %s\n", buffer);
      write(new_sd, "This is the acknowlegement from the server\n", 44);
      n--;
    }
    close(new_sd);
    close(sd);
    return 0;
}
