#include "sock_functions.h"
// client

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0), size_addr = sizeof(struct sockaddr_in);
    struct sockaddr_in server;

    if(sock == -1)
        handle_error("socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(0xAABB);
    server.sin_addr.s_addr = inet_addr(IP);

    /*memset(&my_addr, 0, size_addr);
    my_addr.sun_family = AF_UNIX;
    strncpy(my_addr.sun_path, SOCKNAME, sizeof(my_addr.sun_path) - 1);*/

/////////////////////////////////////////////////////////////////////

    if(connect(sock, (struct sockaddr *)&server, sizeof(struct sockaddr_in)) == -1)
        handle_error("connect");

    puts("Send a message to server");
    ssize_t numRead;
    char buf[BUF_SIZE];
    while((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) 
        write(sock, buf, numRead);

    if(numRead == -1)
        handle_error("read");
    
    return 0;
}
