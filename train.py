from sklearn.naive_bayes import GaussianNB
import random
import numpy as np
import math


no_of_vectors = 100 #no of vectors or samples
vector_dimensions = 2 #each vector or sample has 2 dimensions, the x co-ordinate and the y-cordinate

# 3 cluster of points are generated, because we have 3 target classes
ballRadius = 1.0
x1 = [1.5, 1] +  ballRadius * np.random.randn(no_of_vectors,vector_dimensions) #will belong to class 0
x2 = [-1.5, 1] + ballRadius * np.random.randn(no_of_vectors,vector_dimensions) #will belong to class 1
x3 = [0, -3] + ballRadius * np.random.randn(no_of_vectors,vector_dimensions) #will belong to class 2

# All points are concatenated
# this is the input function for our gausian naieve bayes trainer
X_train=np.concatenate((x1,x2,x3))

# The classes are 0,1 and 2.
# This is the output function for our gausian naieve bayes trainer
Y_train=np.concatenate((np.zeros(NBVECS),np.ones(NBVECS),2*np.ones(NBVECS)))

gnb = GaussianNB()
gnb.fit(X_train, Y_train)

print("Testing")
y_pred = gnb.predict([[1.5,1.0]])
print(y_pred)

y_pred = gnb.predict([[-1.5,1.0]])
print(y_pred)

y_pred = gnb.predict([[0,-3.0]])
print(y_pred)

# Dump of data for CMSIS-DSP

print("Parameters")
# Gaussian averages
print("Theta = ",list(np.reshape(gnb.theta_,np.size(gnb.theta_))))

# Gaussian variances
print("Sigma = ",list(np.reshape(gnb.sigma_,np.size(gnb.sigma_))))

# Class priors
print("Prior = ",list(np.reshape(gnb.class_prior_,np.size(gnb.class_prior_))))

print("Epsilon = ",gnb.epsilon_)


