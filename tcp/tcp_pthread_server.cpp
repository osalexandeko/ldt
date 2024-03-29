/*
    C socket server example, handles multiple clients using threads
    Compile
    gcc server.c -lpthread -o server
*/
 
#include <stdint.h>
#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h>   //for threading , link with lpthread

#include <wiringPi.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <iostream>

#include "protocol_parser.hpp"

pthread_mutex_t    mut_prot_parser;
pthread_mutexattr_t attr_prot_parser_mut;



using namespace std;



 
//the thread function
void *connection_handler(void *);


/**
* Prepare protocol parsers
*/
void prepare_protocol_parsers(){
	if (pthread_mutexattr_init(&attr_prot_parser_mut) != 0) {
		perror("pthread_mutex_attr_init() error");
		exit(1);
	}
 
	//if(0 != pthread_mutexattr_setprotocol(&attr_prot_parser_mut,PTHREAD_PRIO_NONE))
    //if(0 != pthread_mutexattr_setprotocol(&attr_prot_parser_mut,PTHREAD_PRIO_INHERIT))
    if(0 != pthread_mutexattr_setprotocol(&attr_prot_parser_mut,PTHREAD_PRIO_PROTECT))
	{
      perror("pthread_mutexattr_setprotocol  error");
      exit(1);
    }
	pthread_mutex_init(&mut_prot_parser,&attr_prot_parser_mut);
}

/*
* Clean after protocol parsers.
*/
void clean_after_protocol_parsers(){
	pthread_mutex_destroy(&mut_prot_parser);
}
 
int main(int argc , char *argv[])
{
	
	prepare_protocol_parsers();
	
    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; 
    server.sin_port = htons( 8888 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
     
       
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
	pthread_t thread_id;
	
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");
         
        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        pthread_join( thread_id , NULL);
        puts("Handler assigned");
    }
     
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
     
	close(client_sock); 
	clean_after_protocol_parsers(); 
	pthread_mutex_destroy(&mut_prot_parser);
    return 0;
}
 
/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char message[2][64] = {"Greetings! I am your connection handler\n","Now type something and i shall repeat what you type \n"} , client_message[2000];
    
	protocol_parser pp(&mut_prot_parser);
	
    //Send some messages to the client
    
    write(sock , message[0] , strlen(message[0]));
    write(sock , message[1] , strlen(message[1]));
	

 
	//Receive a message from client
	while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
	{
		//end of string marker
		client_message[read_size] =  ((int)socket_desc) & 0xFF;
		client_message[read_size] =  (((int)socket_desc) >> 8) & 0xFF;
		
		client_message[read_size + 2] = '\0';
		
		//Send the message back to client
		write(sock , client_message , strlen(client_message));
		
		cout << client_message << endl;
		
		pp.parse_and_execute(client_message);
		
		//clear the message buffer
		memset(client_message, 0, 2000);
		
		
		
	}
	 
	if(read_size == 0)
	{
		puts("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		perror("recv failed");
	}
   
    return 0; 
}