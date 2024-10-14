#include<stdio.h>
#include<math.h>


float radian_mult = ((3.1416) /180)

 
double sum(double x, double y) {
    double add;
    add =x+y;
    return add;
}


double subt(double x, double y) {
    double subtract;
    subtract =x-y;
    return subtract;
}

double mult (double x, double y) {
    double multiplication;
    multiplication = x*y;
    return multiplication;
}

double divi (double x, double y) {
    double divide;
    divide = x/y;
    return divide;
}

double square (double x) {
    double sq = x*x;
    return sq;
}

double cub (double x) {
    double cube = x*x*x;
    return cube;
}

double acos(double angle);
double asin(double angle);
double atan(double angle);
double cos(double angle);
double sinx(double angle) {
    angle = angle * radian_mult;
    return sin(angle);
}
double tan(double x);
double log10(double x); //10 based logartihm
double pow (double x, double y);
double sqrt (double x);

int factorial(int n)
{
    int i,fac=1;
        for(i=1;i<=n;i++)
            fac*=i;

    return fac;
}

