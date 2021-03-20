

#include <math.h>
#include <stdio.h>
#include "arm_math.h"


arm_gaussian_naive_bayes_instance_f32 S;

#define NUM_OF_CLASSES 3
#define VEC_DIM 2

const float32_t theta[NUM_OF_CLASSES*VEC_DIM] = {}; /**< Mean values for the Gaussians */

const float32_t sigma[NUM_OF_CLASSES*VEC_DIM] = {}; /**< Variances for the Gaussians */

const float32_t classPriors[NUM_OF_CLASSES] = {
  0.3333333333333333f, 0.3333333333333333f, 0.3333333333333333f
}; /*< Class prior probabilities */

int32_t main(void)
{
  /* input with 2 dimensions*/
  float32_t in[2];

  /* Result of the classifier */
  float32_t result[NUM_OF_CLASSES];
  float32_t maxProba;
  uint32_t index;
  
  S.vectorDimension = VEC_DIM; 
  S.numberOfClasses = NUM_OF_CLASSES; 
  S.theta = theta; /* mean values */         
  S.sigma = sigma; /* variance */        
  S.classPriors = classPriors; /* probability of occurence of each class 1/3,1/3,1/3 in this case */    
  S.epsilon=4.328939296523643e-09f; 

  in[0] = 1.5f;
  in[1] = 1.0f;

  index = arm_gaussian_naive_bayes_predict_f32(&S, in, result);

  maxProba = result[index];

#if defined(SEMIHOSTING)
  printf("Class = %d\n", index);
#endif

  in[0] = -1.5f;
  in[1] = 1.0f;

  index = arm_gaussian_naive_bayes_predict_f32(&S, in, result);

  maxProba = result[index];

#if defined(SEMIHOSTING)
  printf("Class = %d\n", index);
#endif

  in[0] = 0.0f;
  in[1] = -3.0f;

  index = arm_gaussian_naive_bayes_predict_f32(&S, in, result);

  maxProba = result[index];

#if defined(SEMIHOSTING)
  printf("Class = %d\n", index);
#endif

#if !defined(SEMIHOSTING)
  while (1); /* main function does not return */
#endif
}

