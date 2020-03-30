#include "sock_functions.h"
// server

#define BACKLOG 5

int main(int argc, char *argv[]) {
    int sock = socket(AF_UNIX, SOCK_STREAM, 0), size_addr = sizeof(struct sockaddr_un);
    struct sockaddr_un my_addr;

    if(sock == -1)
        handle_error("socket");

    if(remove(SOCKNAME) == -1 && errno != ENOENT)
        handle_error("remove");
    
    memset(&my_addr, 0, size_addr);
    my_addr.sun_family = AF_UNIX;
    strncpy(my_addr.sun_path, SOCKNAME, sizeof(my_addr.sun_path));

////////////////////////////////////////////////////////////////////////

    if(bind(sock, (struct sockaddr *) &my_addr, size_addr) == -1)        
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
        //if(write(STDOUT_FILENO, buf, numRead) != numRead)
            //fatal("partial/failed write");

    if(numRead == -1)
        handle_error("read");

    if(close(new_sock) == -1)
        handle_error("close");

    //remove(SOCKNAME);
    return 0;
}








