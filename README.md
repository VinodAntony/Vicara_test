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
-> The parameters are dumped to a txt file. The following parameters were obtained during the run: 
```
Theta =  [1.387475824161616, 0.8800443869905078, -1.6720396473828638, 0.9348414373983904, -0.07495431391816572, -2.899784943630995]
Sigma =  [0.980470340849684, 1.18166934802584, 1.0641256105658998, 1.0040083397932336, 0.917027316127453, 0.9105702307997193]
Prior =  [0.3333333333333333, 0.3333333333333333, 0.3333333333333333]
Epsilon =  4.253690631668857e-09
```
## 2. Setting Up Keil MDK 

-> Target STM32 board : STM32 NUCLEO - F411RE 
	ARM Cortex M4, 100MHz max clock , 512kB ROM, 128kB RAM 

-> Debug: ST-Link Debugger (comes with the board)

-> 


