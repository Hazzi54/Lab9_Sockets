#include "sock_functions.h"
// server

#define BACKLOG 5

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0), size_addr = sizeof(struct sockaddr_in);
    struct sockaddr_in server;

    if(sock == -1)
        handle_error("socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(0xAABB);
    server.sin_addr.s_addr = inet_addr(IP);

    /*if(remove(SOCKNAME) == -1 && errno != ENOENT)
        handle_error("remove");
    
    memset(&my_addr, 0, size_addr);
    my_addr.sun_family = AF_UNIX;
    strncpy(my_addr.sun_path, SOCKNAME, sizeof(my_addr.sun_path));*/

////////////////////////////////////////////////////////////////////////

    if(bind(sock, (struct sockaddr *) &server, size_addr) == -1)        
        handle_error("bind");

    if(listen(sock, BACKLOG) == -1)
        handle_error("listen");

    int new_sock = accept(sock, NULL, 0);
    if(new_sock == -1)
        handle_error("accept");

    ssize_t numRead;
    char buf[BUF_SIZE];
    while((numRead = read(new_sock, buf, BUF_SIZE)) > 0) 
        write(STDOUT_FILENO, buf, numRead);

    if(numRead == -1)
        handle_error("read");

    if(close(new_sock) == -1)
        handle_error("close");

    return 0;
}
