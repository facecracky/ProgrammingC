#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool kort(double a, double b, double c);
double p(double a, double b, double c);
double s(double a, double b, double c);
double h(double a, double b, double c);

//triangle.c

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool kort(double a, double b, double c){
    return (a + b > c) && (a + c > b) && (c + b > a);
}

double p(double a, double b, double c) {
    return a + b + c;
}
