// RFC 1071 - Computing the Internet Checksum

// IPv4 Header Checksum is 16 bits in size
/*The sender and receiver agree on a certain fixed polynomial called the generator
polynomial*/

#include<stdio.h>
#include<stdlib.h>
    
int main(){

register long sum = 0;
__uint32_t count, checksum;
unsigned short addr;

        while( count > 1 )  {
           /*  This is the inner loop */
               sum += addr++;
               count -= 2;
       }

           /*  Add left-over byte, if any */
       if( count > 0 )
               sum += addr;

           /*  Fold 32-bit sum to 16 bits */
       while (sum>>16)
           sum = (sum & 0xffff) + (sum >> 16);

       checksum = ~sum;


       printf("%x\n",checksum);
   }