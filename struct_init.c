
#include <stdlib.h>

#include "header.h"

parameters *param_init (double complex u, double A, double B, int N,
                        double S0, double T,double r, double K,
                        double V0, double sigma, double kappa,
                        double theta, double rho) {

        parameters *init;
        init = (parameters *) malloc(sizeof(parameters));

        if (init == NULL) {

            printf("memory error");
        }

        init -> u = u;
        init -> A =A; 
        init -> B = B; 
        init -> N = N; 
        init -> S0 = S0; 
        init -> T = T; 
        init -> r = r; 
        init -> K = K; 
        init -> V0 = V0;                  
        init -> sigma = sigma; 
        init -> kappa = kappa; 
        init -> theta = theta; 
        init -> rho = rho;

        return init;
}