# Polynomial Regression

[TOC]

## Concept

Linear model may encounter **underfitting**

- It is not powerful
- Not expressive (No twist and curves)
- Extra samples will not help

But we can **add polynomial terms** to the input matrix

- Allows linear model to fit non-linear data

Polynomial terms may cause **overflowing issues**, ==feature scaling== is required.

## Pipeline

### Generate non-linear terms (using PolynomialFeatures)

```python
from sklearn.preprocessing import PolynomialFeatures #using the library

print('Before adding polynomial term:')
print(X[:5])

# Task: create instance of PolynomialFeatures
# poly =
poly = PolynomialFeatures(degree = 2, include_bias = False) #linreg will handle the bias in .fit()

# Task: use poly to transform X to Xp
# Xp =
Xp = poly.fit_transform(X)

print('\nAfter adding polynomial term:')
print(Xp[:5])
```

### Standardize the input matrix (using StandardScaler)

```python
from sklearn.preprocessing import StandardScaler

# Task: create instance of StandardScaler
# scaler =
scaler = StandardScaler()

# Task: use scaler to transform Xp to Xps
# Xps =
Xps = scaler.fit_transform(Xp)

print('After standardization:')
print(Xps[:5])
```

### Training with the transformed input matrix

Use normal LR and calculate RMSE

### Controlling Overfitting with Regularization

#### Modify the cost function by adding a regularization term

$$
j(\theta)=MSE(\theta)+\alpha\frac{1}{2}\sum_{i=1}^{n}{\theta_i^2}
$$

#### Regularized Normal Equation

$$
\hat{\theta}=(X^T\cdot{X}+\alpha{A})^{-1}X^T\cdot{y}
$$

### Ridge Regressor

```python
from sklearn.linear_model import Ridge

# create a Ridge regressor
ridge_reg = Ridge(alpha = 0.1, solver = "cholesky") #alpha is regularization strength

# train the model
ridge_reg.fit(Xp20_scaled,y)
ridge_pred = ridge_reg.predict(Xp20_scaled)

# Compute the RMSE for the model
ridge_pred_rmse = np.sqrt(mean_squared_error(ridge_pred,y))
print("Ridge model (RMSE)", ridge_pred_rmse)

# Visualize the result
show_samples(X, y, axis=[-10, 10, -15, 70])
plot_polymodel(ridge_reg, poly, scaler, 'r-', 'alpha = 0.1')
plt.legend()
plt.show()
```

### Plotting Function

```python
def show_samples(X, y, axis=[0,2,0,12]):
    fig = plt.figure(figsize=(8, 6))
    plt.plot(X, y, 'b.', markersize = 12, label = 'samples')
    plt.xlabel ('$x_1$', fontsize=18)
    plt.ylabel('$y$', fontsize=18)
    plt.axis(axis)
    plt.legend(loc='best')
```

```python
def plot_polymodel (linreg, poly, scaler, style, label):
    # generate uniformly spaced samples in the range [-10, 10]
    Xtest =  np.linspace(-10, 10, 100).reshape(-1, 1)
    # subjected to the same preprocessing steps as the training set
    Xtest_p  = poly.transform(Xtest)
    Xtest_ps = Xtest_p
    if scaler != None:
        Xtest_ps = scaler.transform(Xtest_p)
    # predict and plot
    h = linreg.predict(Xtest_ps)
    plt.plot(Xtest, h, style, label=label)
```

#### Example Usage

```python
#Linear
Xtest =  np.linspace(-10, 10, 100).reshape(-1, 1)
ypred = linreg.predict(Xtest)
show_samples(X, y, axis=[-10, 10, -15, 70])
plt.plot (Xtest, ypred, 'r-', label = 'model (LinearRegression)')
plt.legend()
plt.show()

#Poly
show_samples(X, y, axis=[-10, 10, -15, 70])
plot_polymodel(ridge_reg, poly, scaler, 'r-', 'alpha = 0.1')
plt.legend()
plt.show()
```
