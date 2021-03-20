# Vicara_test

## 1. Initial Dataset and Training:

-> The data is generated randomly using numpy, math and the random modules.

-> The generated data along with the output target classes are passed to an estimator (Gaussian Naieve Bayes in this case) provided by the scikit-learn module.  

-> The trainer provides us with 4 parameters which are required for the next step
	- Theta
	- Sigma
	- Prior
	- Epsilon
	Values are noted and are to be used for the following structure from the CMSIS-DSP library:
```
typedef struct
{
  uint32_t vectorDimension;  /**< Dimension of vector space */
  uint32_t numberOfClasses;  /**< Number of different classes  */
  const float32_t *theta;          /**< Mean values for the Gaussians */
  const float32_t *sigma;          /**< Variances for the Gaussians */
  const float32_t *classPriors;    /**< Class prior probabilities */
  float32_t epsilon;         /**< Additive value to variances */
} arm_gaussian_naive_bayes_instance_f32;
```



