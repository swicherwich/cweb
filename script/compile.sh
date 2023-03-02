#!/bin/sh

gcc ../src/socket_server.c ../src/logs.c ../src/server.c ../src/response.c ../src/request.c -o ../out/socket_server

./../out/socket_server