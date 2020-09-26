# APRIL 2019

[TOC]

## Section A

### 1)

a)i)

Stage, scene, nodes

a)ii)

start()

a)iii)

```java
import javafx.application.Application;

class HelloWorld extends Application {
    
}
```

a)iv)

```java
ImageView img = new ImageView(".../");
```

b)

Launch application

Start method is invoked

c)

i)

```java
btn.setOnMouseClicked(e -> {
    System.out.println("Hello World");
})
```

ii)

```java
Scene scene = new Scene(root, 300, 250);
primaryStage.setStage(scene);
primaryStage.show();
```

iii)

```java
public static void main (String[] args) {
    launch(args);
}
```

### 2)

a)i) 

Change the \ to /

a)ii)

amount is 32.32 32.32

amount is 32.3200 32.3200



### 3)

a) i)

ii)

iii)

Prints the throwable object and its call stack trace info

b) i)

```java
public static void Q3_b (double a, double b) {
    try {
       System.out.println(divide(a, b));  
    } catch (IllegalArgumentException e) {
        System.out.println(e);
    }
}

public double divide(double numerator, double denominator) {
    if (denominator == 0)
        throw new IllegalArgumentException("The divisor is zero");
    else
        return numerator / denominator;
}
```

c)

i)

```java
extends Runnable
```

ii)

```java
t = new Thread(this);
t.start();
```

iii)

```java
catch (InterruptedException e) {
    System.out.println(e);
}
```

iv)

```java
RunnableDemo R2 = new RunnableDemo("Thread-2");
R2.start();
```

## Section B)

### 4)

```java
public class Circle {
    private double radius;
    private String color;
    
    public Circle() {
        radius = 1.0;
        color = "red";
    }
    
    public Circle(double rad) {
        radius = rad;
      	color = "red";
    }
    
    public double getRadius() {
        return radius;
    }
    
    public double getArea() {
        return Math.PI * radius * radius;
    }
    
    public static void main (String[] args) {
        
    }
}
```

b)

c)

Polymorphism, Encapsulation, Inheritance

### 5)

b)

```java
public abstract class Car {
    private String typeCar;
    private double fuelCan;
    private double engineLife;
    
    public Car(String tCar, double fCan, double eLife) {
        typeCar = tCar;
        fuelCan = fCan;
        engineLife = eLife;
    }
    
    public String getTypeCar() {
        return typeCar;
    }
    
    public double getFuelCan() {
        return fuelCan;
    }
    
    public double getEngineLife() {
        return engineLife;
    }
    
    public void setTypeCar (String tCar) {
        typeCar = tCar;
    }
    
    public void setFuelCan (double fCan) {
        fuelCan = fCan;
    }
    
    public void setEngineLife (double eLife) {
        engineLife = eLife;
    }
    
    public abstract double AdditiveCon();
    
    public abstract double AdditiveLife();
}
```

c)

i) ii)

```java
class Sedan extends Car {
    public Sedan(String tCar, double fCan, double eLife) {
        super(tCar, fCan, eLife);
    }
    
    @Override
    public double AdditiveCon() {
        return getFuelCan() + 1.5;
    }
    
    public double AdditiveLife() {
        return getAdditiveLife() - 0.05;
    }
    
    public void showCarInfo() {
        System.out.println("With additive fuel consumption is " + getFuelCan() + " km/l and engine life is " + getEngineLife());
    }
}

class SUV extends Car {
    public SUV(String tCar, double fCan, double eLife) {
        super(tCar, fCan, eLife);
    }
    
    @Override
    public double AdditiveCon() {
        return getFuelCan() + 1.5;
    }
    
    public double AdditiveLife() {
        return getAdditiveLife() - 0.08;
    }
    
    public void showCarInfo() {
        System.out.println("With additive fuel consumption is " + getFuelCan() + " km/l and engine life is " + getEngineLife());
    }
}
```