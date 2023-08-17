
#ifndef header_H
#define header_H

#include <complex.h>
#include <stdio.h>

#define PI 3.14

typedef struct {

    double complex u;
    double A; 
    double B; 
    int N; 
    double S0; 
    double T; 
    double r; 
    double K; 
    double V0;                  
    double sigma; 
    double kappa; 
    double theta; 
    double rho;

} parameters;

double carr_madan_ft(parameters *ptr, double complex (*e)(parameters *),
                     double (*g)(parameters *, double complex (*)(parameters *)));

double carrmadan_ft_integration_func(parameters *ptr, double complex (*h)(parameters *));

parameters *param_init(double complex u, double A, double B, int N, double S0,
                       double T, double r,double K, double V0, double sigma,
                       double kappa, double theta, double rho);

double heston_trap_integration(parameters *ptr, double complex (*e)(parameters *),
                               double (*g)(parameters *, double complex (*)(parameters *)));

double complex cuirai_heston_characfun(parameters *ptr);

#endif






