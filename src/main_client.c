#include "sock_functions.h"
// client
int main() {
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    struct sockaddr_un addr;
    int size_addr = sizeof(struct sockaddr_un);

    if(sock == -1)
        handle_error("socket");
    
    memset(&addr, 0, size_addr);
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKNAME, sizeof(addr.sun_path) - 1);

/////////////////////////////////////////////////////////////////////

    if(connect(sock, (struct sockaddr *)&addr, size_addr) == -1)
        handle_error("connect");

    ssize_t numRead;
    char buf[BUF_SIZE];
    while((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) 
        write(sock, buf, numRead);
        //if(write(sock, buf, numRead) != numRead)
            //fatal("partial/failed write");

    if(numRead == -1)
        handle_error("read");
    
    return 0;
}
