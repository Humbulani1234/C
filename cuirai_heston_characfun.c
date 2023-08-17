
#include <complex.h>
#include <math.h>

#include "header.h"

double complex cuirai_heston_characfun(parameters *ptr) { 

		  double complex mycomplex = 1.0 +0*I;
		  double complex eta = ptr->kappa - ptr->sigma*ptr->rho*ptr->u*mycomplex;

		  double complex d_2 = sqrt(pow(eta, 2.0) + pow(ptr->sigma, 2.0)\
		  	                         * (pow(ptr->u, 2.0) + mycomplex*ptr->u));

		  double complex g_1 = (eta + d_2)/(eta - d_2);
		  double complex A_1 = (pow(ptr->u, 2.0) + mycomplex*ptr->u)*sinh(d_2*ptr->T/2.0);
		  double complex A_2 = d_2*cosh(d_2*ptr->T/2.0) + eta*sinh(d_2*ptr->T/2.0);
		  double complex A = A_1/A_2;

		  double complex D_2 = log(d_2) + (ptr->kappa - d_2)*ptr->T/2.0\
		                       - log((d_2 + eta)/2.0 + (d_2 - eta)/2.0 * exp(-d_2*ptr->T));

		  double complex ans = exp(mycomplex*ptr->u*(log(ptr->S0) + ptr->r*ptr->T)\
                               - ptr->T*ptr->kappa*ptr->theta*ptr->rho*mycomplex*ptr->u\
				              /ptr->sigma - ptr->V0*A + 2.0*ptr->kappa * ptr->theta\
                              /pow(ptr->sigma,2.0)*D_2);

		  return ans;
}
		  
