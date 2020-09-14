# JS Objects Cheat Sheet

[TOC]

## Objects in JS

JS supports **2** kinds of objects:

1. **Intrinsic ("Built-in")**
   - Array
   - Boolean
   - Date
   - Math
   - String
2. **User-define objects**

## Math Object

### Methods

| Method     | Description                          |
| ---------- | ------------------------------------ |
| `abs(x)`   | Gives the absolute value of x        |
| `ceil(x)`  | Ceiling function                     |
| `cos(x)`   | Cosine function                      |
| `exp(x)`   | Exponential function, e^x^           |
| `floor(x)` | Floor function                       |
| `log(x)`   | Natural log, $\ln x$                 |
| `max(x,y)` | Returns the largest between x and y  |
| `min(x,y)` | Returns the smallest between x and y |
| `pow(x,y)` | Returns x^y^                         |
| `round(x)` | Rounds x to the nearest integer      |
| `sin(x)`   | Sine function                        |
| `sqrt(x)`  | Returns $\sqrt{x}$                   |
| `tax(x)`   | Tangent function                     |

### Constants

| Constants      | Description      |
| -------------- | ---------------- |
| `Math.E`       | $e$              |
| `Math.LN2`     | $\ln2$           |
| `Math.LN10`    | $\ln 10$         |
| `Math.LOG2E`   | $log_2e$         |
| `Math.PI`      | $\pi$            |
| `Math.SQRT1_2` | $\sqrt{\frac12}$ |
| `Math.SQRT2`   | $\sqrt{2}$       |

## String Object

### String Basics

1. **String literals** or **String constants** are *sequence of characters* wrapped in `""` or `''`
   - `let str1 = 'Hello';`
   - `let str2 = "Hello";`
2. `str1 + str2` results in `HelloHello`, this is called **String Concatenation**

### String Methods

| Method                             | Description                                                  |
| ---------------------------------- | ------------------------------------------------------------ |
| `charAt(index)`                    | Returns the character at the index, returns empty string if no character. |
| `charCodeAt(index)`                | Returns Unicode at index, return `NaN` otherwise.            |
| `concat(stringArg)`                | Returns a **new string** appended with the `stringArg` behind. |
| `fromCharCode(val1, val2)`         | Converts each Unicode value into a string of corresponding characters. |
| `indexOf(substring, index)`        | Returns  the first index of the substring starting from the specified index (optional), returns -1 if not found. |
| `lastIndexOf(substring , index)`   | Similar to above but instead searches for last argument.     |
| `replace(searchString, newString)` | Return the modified string, otherwise returns original string if no replacement made. |
| `slice(start, end)`                | ![image-20200811213309891](C:\Users\seann\AppData\Roaming\Typora\typora-user-images\image-20200811213309891.png) |
| `split(string)`                    | ==Very Useful== , splits a string into **array of tokens** based on the provided delimiter. |
| `substr(start, lenghth)`           | ![image-20200811213647713](C:\Users\seann\AppData\Roaming\Typora\typora-user-images\image-20200811213647713.png) |
| `substring(start, end)`            | ![image-20200811213637219](C:\Users\seann\AppData\Roaming\Typora\typora-user-images\image-20200811213637219.png) |
| `toLowerCase()`                    | Returns a string, where **all uppercase chars are converted into lowercase**, **non-letter characters are ignored** |
| `toUpperCase()`                    | Returns a string, where **all lowercase chars are converted into uppercase**, **non-letter characters are ignored** |

## Date Object

Based on either **local time** or **UTC**, most methods have **both**

Date starts counting from **January 1, 1970**

**2 types** of constructors

```javascript
var date1 = new Date();
```

```javascript
var date2 = new Date(year, month, day, hours, minutes, seconds, milliseconds);
```

### Date Methods (Get)

| Method                                          | Description                                                  |
| ----------------------------------------------- | ------------------------------------------------------------ |
| `getDate()`<br />`getUTCDate()`                 | Returns a number $1 \leq x \leq 31$ representing day of month (Local or UTC) |
| `getDay()`<br />`getUTCDay()`                   | Returns a number $0$ (Sunday) $\leq x \leq$ 6 (Saturday)     |
| `getFullYear()`<br />`getUTCFullYear()`         | Returns year as **4 digit number**                           |
| `getHours()`<br />`getUTCHours()`               | Returns $0\leq x \leq 23$ (hours passed since midnight)      |
| `getMilliseconds()`<br />`getUTCMilliseconds()` | Returns $0\leq x\leq999$                                     |
| `getMinutes()`<br />`getUTCMinutes()`           | Returns $0\leq x\leq59$                                      |
| `getMonth()`<br />`getUTCMonth()`               | Returns a number $0$ (January) $\leq x \leq$ 11 (December)   |
| `getSeconds()`<br />`getUTCSeconds()`           | Returns $0\leq x\leq59$                                      |
| `getTime()`                                     | Returns the number of $ms$ since January 1, 1970             |
| `getTimezoneOffset()`                           | Returns the difference between local time and UTC in minutes |

### Set Methods

![image-20200813212708340](C:\Users\seann\AppData\Roaming\Typora\typora-user-images\image-20200813212708340.png)

![image-20200813212751192](C:\Users\seann\AppData\Roaming\Typora\typora-user-images\image-20200813212751192.png)

![image-20200813212825302](C:\Users\seann\AppData\Roaming\Typora\typora-user-images\image-20200813212825302.png)

## Arrays Object

### Array Creation

**2 ways** of creating array (need not to fill with values)

1. `var myArray = [ele0, ele1, ele2 ... eleN];`
2. `var myArray = new Array(ele0, ele1, ele2 ... eleN);`

Access arrays using **square bracket notation**

`myArray[1] = "Omega";`

### Array Linear Access

Array Length

use `myArray.length;` 

Looping through array using the **for-in** loop

```javascript
for(var i in fruits){
    document.write(fruits[i] + "<br>")
}
```

### Array Editing

Add element to the end using

`myArray.push()`

Add to the front using

`myArray.unshift()` **(this will shift all indices by n + 1)**

Remove the last element using

`myArray.pop()`

Remove the first element using

`myArray.shift()`

### Creating a String from an Array

Use the method to join elements into a String

`myArray.join(separator)` **(default separator is comma , )**

### Array Sorting

To sort alphabetically (case-sensitive) use

`myArray.sort()` 

But to achieve case-insensitive sort, must pass in a compare function

**Sorting numbers might give wrong results because it converts them to Strings**

```javascript
var numbers = [5, 20, 10, 75, 50, 100];

numbers.sort((a,b) => return a - b;) // if a is 1, b is 2, 1 - 2 = -1, hence a is before b
```

### Reversing an Array

`myArray.reverse()`

## User-Defined Objects

An object is a **collection of properties**

> Property is the association between name/key and value (can be methods, objects, array....)

### Defining Objects

1. Using the **new keyword**

```javascript
var myObj = new Object(); //this is blank object, we may choose to add properties later
myObj.prop1 = "value1"; //dynamically add a new property
myObj.prop2 = new Object(); //you may nest objects
```

2. Using **Object Initializer** (comma delimited)

```javascript
var Human = {
    fname : "Sean", // key-value pair
    lname : "Ng",
    posn : "CEO",
    age : 20,
    fullName : function() {
        return this.fname + " " + this.lname;
    },
    address : {
        id: 1,
        country: "Mesia"
    }
};
```

3. Using **Constructor function** (capitalize the name of constructors)

```javascript
function Car(model, builtYear){
    this.model = model;
    this.builtYear = builtYear; //this refers to the object that "owns the code"
}
```

### Accessing properties

1. Dot Notation

```javascript
myObj.prop1; // here contains the String "value1"
Human.fullName() //use () to access a method, without () it will give you the definiton instead
Human.address.country //accessing nested objects
```

2. Array Notation

```javascript
myObj["prop1"]; // same
```

Note: Accessing a non existent key gives `undefined`

### Looping through keys

Use the `for-in` loop

```javascript
for(key in person){
    buffer += person[key];
}
```

### Delete a property

```javascript
delete Human.lname //delete keyword followed by Property
```

### Array of Objects

```javascript
var Humans = [{fname : "Sean", age: 20},{fname : "Roger", age: 29}]
```

## JSON

Similar to JS Objects

```json
{"name":"Sean"}
```

**keys** must be String with **double quotes**, and **values** can be:

- String
- Number
- Object (JSON Object)
- Array `[value1, value2, value3]`
- boolean
- null

### Reading JSON

```javascript
var obj = JSON.parse('{"name":"John"}');
```

### Sending JSON

```javascript
var jsonStr = JSON.stringify(obj);
```

