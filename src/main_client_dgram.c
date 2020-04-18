#include "sock_functions.h"
// client

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0), size_addr = sizeof(struct sockaddr_in);
    struct sockaddr_in server;

    if(sock == -1)
        handle_error("socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(0xAABB);
    server.sin_addr.s_addr = inet_addr(IP);

/////////////////////////////////////////////////////////////////////

    ssize_t numBytes;
    char buf[BUF_SIZE], buf2[BUF_SIZE] = "\n";
    int i = 0;
    size_addr = sizeof(server);
    puts("Convert to uppercase:");
    while(i < 10) {
        fgets(buf, BUF_SIZE, stdin);
        if(sendto(sock, buf, sizeof(buf), 0, (struct sockaddr *) &server, size_addr) < 0)
            handle_error("sendto");

        numBytes = recvfrom(sock, buf2, BUF_SIZE, 0, (struct sockaddr *) &server, &size_addr);
        if(numBytes == -1)
            handle_error("recvfrom");
        puts(buf2);
        i++;
    }
    
    return 0;
}
