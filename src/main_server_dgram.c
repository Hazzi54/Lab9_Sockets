#include "sock_functions.h"
// server

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0), size_addr = sizeof(struct sockaddr_in);
    struct sockaddr_in server, client;

    if(sock == -1)
        handle_error("socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(0xAABB);
    server.sin_addr.s_addr = inet_addr(IP);

////////////////////////////////////////////////////////////////////////

    if(bind(sock, (struct sockaddr *) &server, size_addr) == -1)        
        handle_error("bind");

    ssize_t numBytes;
    char buf[BUF_SIZE];
    int i;
    while(1) {
        size_addr = sizeof(client);
        numBytes = recvfrom(sock, buf, BUF_SIZE, 0, (struct sockaddr *) &client, &size_addr);
        if(numBytes == -1)
            handle_error("recvfrom");

        printf("Server received %s from %d %d\n", buf, client.sin_port, client.sin_addr.s_addr);

        i = 0;
        while(i < numBytes) {
            buf[i] = toupper((unsigned char) buf[i]);
            i++;
        }
        
        if(sendto(sock, buf, numBytes, 0, (struct sockaddr *) &client, size_addr) != numBytes)
            handle_error("sendto");
    }
    return 0;
}
