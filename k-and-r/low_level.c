#include <stdio.h>

#define print_fmt(x) (_Generic((x), \
int: "%d",                         \
double: "%f",                      \
default: "%x"))


//#define print(x) printf(print_fmt(x), x ); puts("");
int main(){

    print_fmt(10);
    print_fmt('f');
}