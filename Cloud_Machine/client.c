#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 5555

int main(){
    struct sockaddr_in serv;
    int sd;
    char buffer[1000];
    char ack[100];
    sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    inet_pton(AF_INET, "49.36.35.241", &serv.sin_addr);
    serv.sin_port = htons(PORT);

    connect(sd, (struct sockaddr *)&serv, sizeof(serv));
    printf("Connected to the server..\n");
    int n = 5;
    while(n)
    {
      printf("Enter a message for the server\n");
      scanf("%[^\n]", buffer);
      getchar();
      write(sd, buffer, sizeof(buffer));
      read(sd, ack, sizeof(ack));
      printf("The message received from the server is : %s\n", ack);
      n--;
    }
    close(sd);


    return 0;
}
