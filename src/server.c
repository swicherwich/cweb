#include "libs/server.h"
#include "libs/logs.h"

#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>

void init_server(http_server *server, int port, int queue)
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1)
    {
        log_error("Could not create socket.");
        return;
    }
    log_info("Socket created");

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    server->port = port;
    server->socket = server_socket;

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0)
    {
        log_error("Could not bind socket");
        return;
    }
    log_info("Socket binded");

    log_info("Listenning for connections...");
    printf("%s Port: %d\n", PREFIX_INFO, port);
    listen(server_socket, queue);

}