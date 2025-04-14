#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool kort(double a, double b, double c){
    return (a + b > c) && (a + c > b) && (c + b > a);
}

double p(double a, double b, double c) {
    return a + b + c;
}


double s(double a, double b, double c){
    double py = p(a, b, c)/2;
    return sqrt(py*(py - a)*(py - b)*(py - c));
}

double h(double a, double b, double c){
    double py = p(a, b, c)/2;
    double s = sqrt(py*(py - a)*(py - b)*(py - c));
    return (2*(s))/a;
}