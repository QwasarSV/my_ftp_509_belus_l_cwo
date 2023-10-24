#include <string.h>
#include <unistd.h>

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <my_socket.hpp>

#include <my_TCP_server.hpp>

#define RW_SIZE 512