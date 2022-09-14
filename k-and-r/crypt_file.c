#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *f;
    char c;
    f=fopen("test.txt","rt");

    while((c=fgetc(f))!=EOF){
       // c = c & 1;
        printf("%c",c);
    }

    fclose(f);
    return 0;
}