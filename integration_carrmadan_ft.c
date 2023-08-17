
#include <complex.h>
#include <math.h>
#include <stdlib.h>

#include "header.h"

double carrmadan_ft_integration_func(parameters *ptr, double complex (*h)(parameters *)) {

      double complex complex1 = 0.0 + -1.0*I;
      double complex complex2 = 0.0 + 1.0*I;

      if (ptr->S0 >= 0.95*ptr->K) {

        double alpha = 1.5;
        double complex complex3 = ptr->u-(alpha+1.0)*complex2;
        ptr->u = complex3*complex2;
        double modified_char = creal(((exp(complex1*ptr->u*log(ptr->K)))*(exp(-ptr->r*ptr->T))\
                               * ((*h)(ptr))/((1.5+complex2*ptr->u)*(1.5+1.0+complex2*ptr->u))));
        return modified_char;
       }
       
      else {

        double alpha = 1.1;
        double complex complex4 = ptr->u+complex2*alpha-complex2;
        ptr->u = complex4*complex2;
        double component1 = creal((1.0/(1.0+complex2*(ptr->u-complex2*alpha)) - exp(ptr->r*ptr->T)\
                            /(complex2*(ptr->u-complex2*alpha)) - ((*h)(ptr))\
                            /((ptr->u-complex2*alpha)*((ptr->u-complex2*alpha)-complex2)))\
                            *exp(-ptr->r*ptr->T)*exp(complex1*ptr->u*log(ptr->K)));

        double component2 = creal((1.0/(1.0+complex2*(ptr->u+complex2*alpha)) - exp(ptr->r*ptr->T)\
                            /(complex2*(ptr->u+complex2*alpha))- ((*h)(ptr))/((ptr->u+complex2*alpha)\
                            *((ptr->u+complex2*alpha)-complex2)))* exp(-ptr->r*ptr->T)\
                            *exp(complex1*ptr->u*log(ptr->K)));

        double modified_char = (component1 - component2);
        return modified_char;
       }
    
}