#include <stdio.h>

union vec3d {
    struct{
        double x;
        double y;
        double z;
    };
    double raw[3];
};

union vec3d vec;

int main(){

for(double i; i<=3; i++){
printf("%f\n",vec.);
}

}