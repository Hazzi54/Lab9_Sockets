#ifndef _SOCK_FUNCTIONS
#define _SOCK_FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define BUF_SIZE 100

#define IP "127.0.0.1"

void handle_error(char *);

#endif
