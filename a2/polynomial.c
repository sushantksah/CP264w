/*
--------------------------------------------------
Project: a2q2
File:    polynomial.c
Author:  Sushant Sah
Version: 2025-01-17
--------------------------------------------------
*/
#include <stdio.h>
#include "polynomial.h"
#include <math.h>
#define EPSILON 1e-6
#define MAXCOUNT 100

/**
 * Cmpute and return the value of the (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm (https://en.wikipedia.org/wiki/Horner%27s_method)
 *
 * @param *p - pointer to float number array
 * @param n  - the number of coefficients   
 * @return - the value of the above polynomial 
 */
// x = coefficents, n = 
// float *p decays into a pointer to the first element in an array 
float horner(float *p, int n, float x){
    float res = p[0]; // start with leading coefficient 

    for(int i = 1; i < n; i++){
        res = res * x + p[i]; 
    }
    return res; 

}

/**
 * Cmpute the derivative of input (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0 
 * output the coefficients of the derivative polynomial in an array. 
 * The derivative of the above polynomial p(x) is as follows.  
 * p'(x) = (n-1)* p[0]*x^{n-2} +  (n-2)*p[1]*x^{n-3} +...+ p[n-2]*x^0
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param *d - pointer to coefficient array of output polynomial. 
 * @param n  - the number of coefficients of the input polynomial
 */
void derivative(float *p, float *d, int n){
    if(n <= 1){
        d[0] = 0;
        return;
    }

    for(int i=0; i < n -1; i++){
        d[i] = (n - 1 - i) * p[i];
    }
}

/**
 * Compute approximate real root x of polynomial p(x) using Newton's 
 * method(https://en.wikipedia.org/wiki/Newton%27s_method).  
 * Use fault tolerant 1e-6 (or 0.000001) and maximum 100 iterations.
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param n  - the number of coefficients of the input polynomial
 * @param x0 - start point for Newton method
 * @return -  the root if found, otherwise x0.
 */
float newton(float *p, int n, float x0){
    float x = x0, px, d[n-1];
    derivative(p,d,n);

    int count = 0; 
    do {
        x0 = x;
        px = horner(p,n,x); // Compute the value for P(x)
        x = x - px / horner(d, n-1, x);
        count++;
        } while(fabs(px) > EPSILON && fabs(x-x0) > EPSILON);

    return x; 
}
