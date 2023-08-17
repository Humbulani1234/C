
#include <complex.h>
#include <stdlib.h>

#include "header.h"

double heston_trap_integration(parameters *ptr, double complex (*e)(parameters *),
                               double (*f)(parameters *, double complex (*)(parameters *))) { 

        /* Integrate over interval [A, B] using Trapezoidal rule */

    	double res = 0.0;
    	double h = (ptr->B - ptr->A)/ ptr->N;
        double *array; 
        array = (double *) malloc((ptr->N+1) * sizeof(double)); 

    	for (int n = 0; n < ptr->N+1; n++) {

    	      if (n == 0 || n == ptr->N) { 
    	           array[n] = 1; 
               }

    	      else {

    	      	   array[n] = 2;
              }
    	}
        
        for (int n = 0; n < ptr->N+1; n++) {

              double c;
              for (c = ptr->A + (0.5 * h); c < ptr->B; c += h);
              res += array[n] * (*f)(ptr, (double complex *) e);
        }
        
        return res * h;
}
