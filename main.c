

#include <math.h>
#include <stdio.h>
#include "arm_math.h"


arm_gaussian_naive_bayes_instance_f32 S;

#define NUM_OF_CLASSES 3
#define VEC_DIM 2
/* the following values were taken from  Vicara_test/dataset-trainer/output.txt */
const float32_t theta[NUM_OF_CLASSES*VEC_DIM] = {
1.387475824161616f, 0.8800443869905078f, -1.6720396473828638f, 
0.9348414373983904f, -0.07495431391816572f, -2.899784943630995f}; /**< Mean values for the Gaussians */

const float32_t sigma[NUM_OF_CLASSES*VEC_DIM] = {
0.980470340849684f, 1.18166934802584f, 1.0641256105658998f, 
1.0040083397932336f, 0.917027316127453f, 0.9105702307997193f}; /**< Variances for the Gaussians */

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
  S.epsilon= 4.253690631668857e-09f; 

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

