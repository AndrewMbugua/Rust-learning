//constructing a routing information base - A binary tree
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<asm-generic/types.h> //to use with __u32

typedef struct routing_table
{

struct routing_table *source_addr; //parent
__u8 hop_count;
struct routing_table *interface;
__u8 mask;


}routing_table;

routing_table *create_table_entry(__u32 source_addr, __u8 hop_count, __u8 interface, __u8 mask)
{
    routing_table *table_entry = malloc(sizeof(routing_table)); //check for initialization error here
    
    if(table_entry != NULL)
    {
        table_entry -> hop_count = 0;
        table_entry -> interface = NULL;
        table_entry -> source_addr;
        table_entry -> mask;
    }
    return table_entry;
}

//print tree
void print_tree(routing_table *root)
{
 if (root == NULL) {printf("--<empty>--\n"); return;}

printf("|Hop count| \n %d\n",root -> hop_count);

printf("\n|Interface|\n");
print_tree(root -> interface); //recursion

printf("\n|Source address|\n");
print_tree(root -> source_addr);
}

int main(){

//node 1 - first table entry
/*routing_table *entry1 = create_table_entry("127.0.0.1", 0, 200);


The  inet_addr()  function  converts  the Internet host address cp from
IPv4 numbers-and-dots notation into binary data in network byte  order.

printf("IP address:%d\n",inet_addr("127.0.0.1") );
*/


//node 1 - first table entry
routing_table *entry1 = create_table_entry(10,0,200,10);

//parent node
entry1 -> interface = NULL; //NULL for now
entry1 -> hop_count = 0;



print_tree(entry1);







free(entry1);




}