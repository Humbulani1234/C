
#include <unistd.h>
#include <stdlib.h>
#include <complex.h>
#include <stdio.h>
#include <math.h>

#include "header.h"

int main (int argc, char **argv) {

    // double complex u;
    // double A; 
    // double B; 
    // int N; 
    // double S0; 
    // double T; 
    // double r; 
    // double K; 
    // double V0;                  
    // double sigma; 
    // double kappa; 
    // double theta; 
    // double rho;

    parameters *init_st;
    double complex u = 0.0 + 1.0*I;
    init_st = param_init (u, 0.001, 10.0, 200, 100.0, 1.0, 0.01, 50.0, 0.05, 0.5, 2.0, 0.05, -0.8);

    double complex (*charac)(parameters *) = &cuirai_heston_characfun;
    double (*integrate)(parameters *, double complex (*h)(parameters *)) = &carrmadan_ft_integration_func;
    double (*trap_int)(parameters *, double (*h)(parameters *)) = &heston_trap_integration;
    double integral = heston_trap_integration(init_st, (double complex *)charac\
                                              ,(double *) integrate);
    double carr_ft = carr_madan_ft(init_st, (double complex *) charac\
                                   ,(double *) integrate); 

    printf("output %f\n", integral);
    free(init_st);

    return 0;
}
