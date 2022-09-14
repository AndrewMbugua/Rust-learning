//Creating socket
printf("Creating socket...\n");
int socket_listen;
socket_listen = socket(bind_address->ai_family,bind_address->ai_socktype, bind_address->ai_protocol);

if(!ISVALIDSOCKET(socket_listen)){
    fprintf(stderr,"socket() failed. (%d)\n",GETSOCKETERRNO());
    return 1;
}

