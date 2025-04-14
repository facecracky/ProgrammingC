#include <stdio.h>
#include <math.h>
#include "triangle.h"
#include <stdbool.h>

int main(){
    double a, b, c;
    
    printf("Vvedite storoni: ");
    scanf("%lf %lf %lf", &a ,&b ,&c);
    
    while(!kort(a, b, c)){
        if(!kort(a, b, c)){
            printf("Storoni ne vern1e \n");
            printf("Vvedite storoni zanava:");
            scanf("%lf %lf %lf", &a,&b,&c);
        }
    }
    printf("P: %lf \n", p(a, b, c));
    printf("S: %lf \n", s(a, b, c));
    printf("H: %lf \n", h(a, b, c));
    return 0;
}
