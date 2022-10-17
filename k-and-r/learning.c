#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int fd[2];
    char buff[150];
    char data[50];

    //open a pipe
    if(pipe(fd) == -1){
        perror("pipe error");
        exit(1);
    }
    //fd[0] read end && fd[1] write end
    sprintf(buff, "PIPE data flow:"); //output is stored in a character buffer
//write to pipe
    write(fd[1], buff, strlen(buff));
    printf("\n");

//read from pipe
    read(fd[0],data,5);
    printf("%s\n",data);

    read(fd[0], data, 5);
    printf("%s\n",data);

    read(fd[0], data, 10);
    printf("%s\n",data);

}