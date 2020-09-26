# UCCD2044 September 2019 Past Year

[TOC]

## Section A

### 1)

a) i)

Stage - A stage (a window) contains all the objects of a JavaFX application. It is represented by **Stage** class of the package **javafx.stage**. The primary stage is created by the platform itself. The created stage object is passed as an argument to the **start()** method of the **Application** class.

Scene - A scene represents the physical contents of a JavaFX application. It contains all the contents of a scene graph. The class **Scene** of the package **javafx.scene** represents the scene object. At an instance, the scene object is added to only one stage.

 a) ii)

Refer to Eclipse

a) iii)

HBox - lays out its children in a single horizontal row

VBox - lay outs its children in a single vertical row

b)

```java
public void start (Stage primaryStage) {
    Pane pane = new Pane(new Polygon());
    
    Scene scene = new Scene(pane, 400, 400);
    
    primaryStage.setScene(scene);
    
    primaryStage.show();
}
```

c)

Refer to Eclipse

### 2)

a)

i)

InputStream - is used to read data from a source 

OutputStream - is used for writing data to a destination.

ii)

```java
import java.io.DataOutputStream;
import java.io.FileOutputStream;

class Q2a {
    public static void main (String[] args) {
        FileOutputStream fstream = new FileOutputStream("Number.dat");
        DataOutputStream dstream = new DataOutputStream(fstream);
        
        double[] numArr = {1.4, 2.6, 3.7, 4.25, 5.5, 6.8, 10.0};
        
        for(double x : numArr) {
            dstream.writeDouble(x);
        }
    }
}
```

b)

i)

ii)

c)

The DatabaseMetaData interface provides methods to get information about the database you have connected with like, database name, database driver version, maximum column length etc...

### 3)

a)

i)

**Checked:** are the exceptions that are checked at compile time. If some code within a method throws a checked exception, then the method must either handle the exception or it must specify the exception using *throws* keyword.

**Unchecked** are the exceptions that are not checked at compiled time. In C++, all exceptions are unchecked, so it is not forced by the compiler to either handle or specify the exception. It is up to the programmers to be civilized, and specify or catch the exceptions.

In Java exceptions under *Error* and *RuntimeException* classes are unchecked exceptions, everything else under throwable is checked.

ii) Notes

b)

Refer eclipse

c)

Refer notes

d)

### 4)

```java
public class Account {
    private int accountNumber;
   	private double balance;
    
    public Account(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }
    
    public Account(int accNum) {
        accountNumber = accNum;
        balance = 0.0;
    }
    
    public int getAccountNumber() {
        return accountNumber;
    }
    
    public double getBalance() {
        return balance;
    }
    
    public void setBalance(double bal) {
        balance = bal;
    }
    
    public void credit(double amt) {
        balance += amt;
    }
    
    public void debit(double amt) {
        if (balance >= amt) {
            balance -= amt;
		} else {
            System.out.println("Amount Withdrwan exceeds the current balance!");
        }
        
    }
    
    @Override
    public String toString() {
        return String.format("A/C no: %d, Balance = $%.2f", accountNumber, balance);
    }
}
```







