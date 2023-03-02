#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/logs.h"
#include "libs/server.h"
#include "libs/response.h"
#include "libs/request.h"

#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char** argv)
{
    int client_socket;

   http_server http_server;
   init_server(&http_server, 8080, 5);

    while (1)
    {
        log_info("Accepting client connection...");
        client_socket = accept(http_server.socket, NULL, NULL);

        if (client_socket < 0)
        {
            printf("%d\n", client_socket);
            log_error("Could not accept connection");
            return 1;
        }
        log_info("Connection accepted");

        char client_msg[4096];

        if (recv(client_socket, client_msg, 4096, 0) < 0)
        {
            log_error("Error receiving message");
            return 1;
        }

        printf("Msg from client: %s\n", client_msg);

        get_details(client_msg);

        char* server_response = create_response("index.html");

        log_info("Sending response");
        printf("%s", server_response);
        if (send(client_socket, server_response, strlen(server_response), 0) < 0)
        {
            log_error("Error sending message");
            return 1;
        }

        log_info("Message sent");

        close(client_socket);
    }

    return 0;
}
