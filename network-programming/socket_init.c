/*
 * =====================================================================================
 *
 *       Filename:  socket_init.c
 *
 *    Description:  Initializes sockets 
 *
 *        Version:  1.0
 *        Created:  04/08/2022 02:54:10 alasiri
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew Mbugua (mr), andrewmbugua388@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

//When using Berkeley sockets,no special initialization is needed.
//Using Berkley sockets

#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>  
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define GETSOCKETERRNO() (errno)


int main(){

time_t timer;
time(&timer);
//ctime returns the string reps of the local time
printf("Local time: %s",ctime(&timer));

printf("Configuring local address...\n");
struct addrinfo hints; //hints is a pointer towards  addrinfo
memset(&hints, 0, sizeof(hints));

hints.ai_family = AF_INET; //listens to IPv4 addresses
hints.ai_socktype = SOCK_STREAM; //indicates that we're going to be using TCP
hints. ai_flags = AI_PASSIVE; //tells getaddrinto() that we want it to bind to the wildcard address

struct addrinfo *bind_address;
//getaddinfo fills the struct addrinfo with the needed information
//it also generates an address suitable for bind
getaddrinfo(0,"8080", &hints, &bind_address);

//Creating socket
printf("Creating socket...\n");
int socket_listen;
socket_listen = socket(bind_address->ai_family,bind_address->ai_socktype, bind_address->ai_protocol);

if(!ISVALIDSOCKET(socket_listen)){
    fprintf(stderr,"socket() failed. (%d)\n",GETSOCKETERRNO());
    return 1;
}

//calling bind to associate it with our local address from getaddrinfo
printf("Binding socket to local address...\n");
if(bind(socket_listen,bind_address->ai_addr, bind_address-> ai_addrlen)){
    fprintf(stderr, "bind() failed.(%d)\n",GETSOCKETERRNO());
    return 1;
}

freeaddrinfo(bind_address);

//start listening to connections,10 indicates how many connections can queue up
printf("Listening...\n");
if (listen(socket_listen, 10) < 0){
    fprintf(stderr, "listen() failed. %d\n", GETSOCKETERRNO());
    return 1;
}

//accept incoming connections
printf("Waiting for connection...\n");
struct sockaddr_storage client_address;
socklen_t client_len = sizeof(client_address);
SOCKET socket_client = accept(socket_listen,(struct sockaddr*) &client_address, &client_len);

if(!ISVALIDSOCKET(socket_client)){
    fprintf(stderr, "accept() failed. %d\n", GETSOCKETERRNO());
    return 1;
}

//print clients address to the console
printf("Client is connected...");
char address_buffer[100];
getnameinfo((struct sockaddr*) &client_address, client_len, address_buffer, sizeof(address_buffer),0,0, NI_NUMERICHOST);
printf("%s\n", address_buffer);






return 0;
}