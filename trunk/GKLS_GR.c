#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "gkls.h"
#include "rnd_gen.h"
#include "utype.h"

void print_error_msg  (int);

int GKLS_GR(MPAR *Akfun)
{
    unsigned int i, j; /* cycle parameters     */
    int error_code;    /* error codes variable */
    int func_num;      /* test function number within a class     */
    double *xx, dx1, dx2; /* for evaluation of the test function */
    /* on a grid with steps dx1, dx2       */
    double z;          /* test function value  */
    double *g, **h;    /* gradient and hessian matrix */
    
    GKLS_dim = (*Akfun).GKLS_dim;                                             
    GKLS_num_minima = 10;                                     
    if ((error_code = GKLS_domain_alloc()) != GKLS_OK)        
        return error_code;                                     
    GKLS_global_dist = 2.0/3.0;                               
    GKLS_global_radius = 0.5*GKLS_global_dist;                
    GKLS_global_value = GKLS_GLOBAL_MIN_VALUE;                
    if ((error_code = GKLS_parameters_check()) != GKLS_OK)    
        return error_code;                                     
    
    /* Allocate memory for the vector xx of feasible point */
    if ( (xx=(double *)malloc((size_t)GKLS_dim*sizeof(double))) == NULL)
        return (-1);
    
    /* Generate the class of 100 D-type functions */
    //for (func_num=1; func_num <= 100; func_num++)
    func_num=(*Akfun).N_fun;
    if((error_code=GKLS_arg_generate (func_num)) != GKLS_OK) {
        print_error_msg(error_code);
        return error_code;
    }
    
    if (GKLS_dim == 2) {
        /* Function evaluating in the grid 100x100 */
        for (dx1=GKLS_domain_left[0]; dx1<=GKLS_domain_right[0]+GKLS_PRECISION;
             dx1+=(GKLS_domain_right[0] - GKLS_domain_left[0])/100.0)
            for (dx2=GKLS_domain_left[1]; dx2<=GKLS_domain_right[1]+GKLS_PRECISION;
                 dx2+=(GKLS_domain_right[1] - GKLS_domain_left[1])/100.0)
            {
                xx[0]=dx1; xx[1]=dx2;
                if ((*Akfun).tip==1) z=GKLS_D_func(xx);
                if ((*Akfun).tip==3) z=GKLS_ND_func(xx); //-- for ND-type test function 
                if ((*Akfun).tip==2) z=GKLS_D2_func(xx); //-- for D2-type test function 
            }
    } 
    free(xx);
    return 1;
}
/* Print an error message */
void print_error_msg (int error_code)
{
    switch( error_code )
    {
    case GKLS_OK:
        printf("\nGKLS_OK: There is no error.");
        break;
    case GKLS_DIM_ERROR:
        printf("\nGKLS_DIM_ERROR: The problem dimension is out of the valid range [1,%u].",
               (unsigned int)NUM_RND);
        break;
    case GKLS_NUM_MINIMA_ERROR:
        printf("\nGKLS_NUM_MINIMA_ERROR: The number of local minima must be greater than 1.");
        break;
    case GKLS_FUNC_NUMBER_ERROR:
        printf("\nGKLS_FUNC_NUMBER_ERROR: The number of the test function to be generated is out of the range [1,100].");
        break;
    case GKLS_BOUNDARY_ERROR:
        printf("\nGKLS_BOUNDARY_ERROR: The admissible region boundary vectors are not defined or ill-defined.");
        break;
    case GKLS_GLOBAL_MIN_VALUE_ERROR:
        printf("\nGKLS_GLOBAL_MIN_VALUE_ERROR: The global minimum value must be greater than %f.",
               (double)GKLS_PARABOLOID_MIN);
        break;
    case GKLS_GLOBAL_DIST_ERROR:
        printf("\nGKLS_GLOBAL_DIST_ERROR: The distance from the paraboloid vertex to the global minimizer is too great.");
        break;
    case GKLS_GLOBAL_RADIUS_ERROR:
        printf("\nGKLS_GLOBAL_RADIUS_ERROR: The radius of the attraction region of the global minimizer is too high.");
        break;
    case GKLS_MEMORY_ERROR:
        printf("\nGKLS_MEMORY_ERROR: There is not enough memory to allocate.");
        break;
    case GKLS_DERIV_EVAL_ERROR:
        printf("\nGKLS_DERIV_EVAL_ERROR: An error occurs during derivative evaluation.");
        break;
    case GKLS_FLOATING_POINT_ERROR:
    default :
        printf("\nUnknown error.");
    }
    printf("\n");
} /* print_error_msg() */


