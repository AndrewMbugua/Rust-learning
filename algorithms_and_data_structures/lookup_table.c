/*Supposed to implement the hackmem algorithm

which counts the 1 bits in a given value
Though not working as expected
*/

#include<stdio.h>

int pop(unsigned x) {
// Table lookup.
static char table[256] = {
0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,

4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
printf("%d\n", table[x & 0xFF] +
table[(x >> 8) & 0xFF] +
table[(x >> 16) & 0xFF] +
table[(x >> 24)]
);

}
int main (){
     

pop(24);


}