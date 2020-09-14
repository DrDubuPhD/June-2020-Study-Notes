# P07: Creating LR Model

[TOC]

## Intro to Python Classes

### Defining a class

```python
class Pet:
    
    def __init__(self, pName): # __init__ refers to the constructor
        self.name = pName # name is an instance field of class Pet
        
    # other methods go here...
```

`self` is a keyword, similar to `this` in other languages.

### Create an instance

It is similar to other languages,

```python
my_pet = Pet('garfield')
```

Call `Pet()` (constructor), and pass in the related arguments

### General Facts 

1. Functions that receive `self` as 1st parameter are **instance methods**.
2. Variables that are prefixed with `self.` are **instance variables**.
3. When invoking methods, `self` is **implicitly** passed in.

## Normal Equation

### Creating the class

We split the class into several parts, for LR we need **3** components

1. A constructor (to initialise $\theta$ if user provides)
2. `fit()` method to produce all $\theta$ (parameters/weight, depends on `n`)
3. `predict()` method to produce output `h` , usually of size `(m,1)`

### `predict()` Method

Step 1, get the **no. of samples, m** and **no. of features, n** from the training sample x

```python
m, n = np.size(X,0), np.size(X,1)  # or m, n = np.shape
```

Step 2, append (use `np.hstack()`) the column of **bias terms $x_1=0$ ** to `X`

```python
X0 = np.hstack((np.ones((m,1), dtype = int), X))
```

Step 3, calculate the output `h` using `np.dot()`

```python
h = np.dot(X0, self.theta)
```

### `fit()` Method

Step 1, find `m, n`, of `X` **(same as above)**

Step 2, call `np.hstack()` to append **bias terms** to `X` **(same as above)**

Step 3, compute the best $\theta$ (parameters) using the formula $\hat\theta = (X^TX)^{-1}X^Ty$

```python
theta_best = np.linalg.inv(X0.T.dot(X0)).dot(X.T.dot(y))
```

## The Cost Function

It is a way **to evaluate** **how good is our model**.

### RMSE

For regression problems, ==***RMSE***== is used as the cost function.

- Normal Version : $RMSE = \sqrt{\frac{1}{m}\sum_{i=1}^m (h^{(i}) - y^{(i)})^2}$
- Vectorized Version : $RMSE = \sqrt{\frac{1}{m}(\textbf{h} - \textbf{y})^T(\textbf{h} - \textbf{y})}$

#### Python Code (Vectorised)

```python
rmse = np.sqrt((1/len(y_true))*((y_pred - y_true).T.dot(y_pred - y_true)))
```

## Batch Gradient Descent (BGD)

### Creating the class (Similar to Normal Equation)

We split the class into several parts, for BGD we need **3** components

1. A constructor (to initialise $\theta$ if user provides)
2. `fit()` method to update the $\theta$ each epoch (GD occurs here)
3. `predict()` method to produce output `h` , usually of size `(m,1)`

### `predict()` Method

Step 1, get the no. of samples, m and no. of features, n from the training sample x

```python
m, n = np.size(X,0), np.size(X,1)  # or m, n = np.shape
```

Step 2, append (use `np.hstack()`) the column of **bias terms $x_1=0$ ** to `X`

```python
X0 = np.hstack((np.ones((m,1), dtype = int), X))
```

Step 3, calculate the output `h` using `np.dot()`

```python
h = np.dot(X0, self.theta)
```

### `fit()` Method

Step 1, find `m, n`, of `X` **(slightly different)**

```python
X0 = np.hstack((np.ones((np.size(X,0),1), dtype = int), X))
m, n = X0.shape # n will be no. of features + 1 (bias term)
```

Step 2, call `np.hstack()` to append **bias terms** to `X` **(same as above)**

Step 3, guess an initial random $\theta$ from the normal distribution

```python
self.theta = np.random.randn(n,) # size -> (n+1,)
```

Step 4, performing GD

```python
for iterations in range(max_iter): # we use stopping condition 1
            gradients = (2/m) * (X0.T.dot(X0.dot(self.theta) - y))
            self.theta = self.theta - learning_rate * gradients
```

