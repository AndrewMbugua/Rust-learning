#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
A cmd line utility to be used with bgp
--help lists all the options

*/
void info(){ printf("BGP utility, type *./cli --help* for more information\r\n");}


void help(){
printf("****Choose an option to learn more****\n\n");

printf("1. Neighbor configuration - neighbor ip_address remote-as  as_number\n\n");

printf("2. Show ip bgp summary - will show the following:\n\n");

printf("x network entries occupying y bytes of memory\nx path entries occupying y bytes of memory\nx network entries\n\n");      
    
}

int main(int argc, char *argv[]){

if(argc == 1){
    info();
}
int *help_msg = malloc(sizeof(int));
*help_msg = strcmp(argv[1], "--help");

if(*help_msg == 0){ help(); }


}