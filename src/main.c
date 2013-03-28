//
//  main.c
//  rasp-find-server
//
//  Created by Caio Lima on 27/03/13.
//  Copyright (c) 2013 Five ITs. All rights reserved.
//

/*
 C socket server example
 */

#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

int main(int argc , char *argv[]){
    
    do{
        int socket_desc , client_sock , c , read_size;
        struct sockaddr_in server , client;
        char client_message[2000];
        
        //Create socket
        socket_desc = socket(AF_INET , SOCK_STREAM , 0);
        if (socket_desc == -1){
            printf("Could not create socket");
        }
        
        
        //Prepare the sockaddr_in structure
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons( 8000 );
        
        //Bind
        if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
        {
            perror("bind failed. Error");
            return 1;
        }
        
        
        //Listen
        listen(socket_desc , 3);
        
        c = sizeof(struct sockaddr_in);
        
        //accept connection from an incoming client
        client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        
        
        printf("Client connected");
        //Receive a message from client
        while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ){
            //Send the message back to client
            puts(client_message);
            write(client_sock , client_message , strlen(client_message));
        }
    }while(1);
    
    return 0;
}
