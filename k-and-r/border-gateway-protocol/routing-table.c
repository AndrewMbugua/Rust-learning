//constructing a routing information base - A binary tree
#include<stdint.h>

/*Routing table
1. Destination network
2. Netmask
3. Gateway
4. Interface
5. Metric - the routing metric of the path through which the packet is to be sent.
           The route will go in the direction of the gateway with the lowest metric.
*/

typedef struct routing_table
{
__uint32_t destination_address;
__uint32_t network_mask;
__uint32_t gateway;
__uint32_t interface;
__uint8_t metric;

}table;

int main(){



}