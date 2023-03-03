#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/logs.h"
#include "libs/server.h"
#include "libs/response.h"
#include "libs/request.h"
#include "libs/routes.h"

#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

char* index();
char* not_found();

int main(int argc, char** argv)
{
    int client_socket;

    http_server http_server;
    init_server(&http_server, 8080, 5);

    route_bind("/", index);
    route_bind("/404", not_found);

    while (1)
    {
        log_info("Accepting client connection...");
        client_socket = accept(http_server.socket, NULL, NULL);

        if (client_socket < 0)
        {
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

        log_info("Msg from client: %s\n", client_msg);

        Request_details request_details = get_details(client_msg);

        log_info("%s Route: %s\n", PREFIX_INFO, request_details.route);

        char* server_response = route_req(request_details.route);

        log_info("%s Server response:\n %s", PREFIX_INFO, server_response);

        log_info("Sending response");

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

char* index()
{
    return create_response("index.html");
}

char* not_found()
{
    return create_response("404.html");
}