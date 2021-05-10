#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>

struct sockaddr_in serv;
int fd;
int conn;
char message[100] = "";

int main() {
  serv.sin_family = AF_INET;
  serv.sin_port = htons(8080);
  serv.sin_addr.s_addr = INADDR_ANY;

  fd = socket(AF_INET, SOCK_STREAM, 0);

  bind(fd, (struct sockaddr *)&serv, sizeof(serv));

  listen(fd, 5);

  while(conn = accept(fd, (struct sockaddr *) NULL, NULL)) {
    int pid;
    if((pid = fork()) == 0) {
      while(recv(conn, message, 100, 0)>0) {
        printf("Message Received: %s\n", message);
      }
      exit(0);
    }
  }
  return 0;
}
