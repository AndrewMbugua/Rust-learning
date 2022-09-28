#include <stdlib.h>
#include<stdio.h>

int main(){

int *pint = NULL;
int count = 10;

pint = malloc(10 * sizeof(int));

if(pint == NULL){ printf("\n malloc failed"); exit(-1); }

printf("\n malloc successful");

for(count = 0; count < 10; count++){
   pint[count] = count;
}

for(count = 0; count < 10; count++){
    printf("\n pint[%d] = (%d)", count,pint[count]);
}

free(pint);


}