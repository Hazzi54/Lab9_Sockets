#ifndef _SOCK_FUNCTIONS
#define _SOCK_FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SOCKNAME "/tmp/us_xfr"
#define BUF_SIZE 100

void handle_error(char *);

#endif
