# File Input and Output (I/O)

- [File Input and Output (I/O)](#file-input-and-output-io)
  - [Writing text to file (PrintWriter)](#writing-text-to-file-printwriter)
    - [Prevent File Truncation](#prevent-file-truncation)
    - [PrintWriter Methods](#printwriter-methods)
  - [Reading Data using Scanner](#reading-data-using-scanner)
    - [Scanner Methods](#scanner-methods)
    - [`hasNext()` Method](#hasnext-method)
    - [Binary I/O Classes](#binary-io-classes)
    - [Binary File Output](#binary-file-output)
    - [Binary File Input](#binary-file-input)
      - [Reminders for Bin. IO](#reminders-for-bin-io)

---

Similar to `fstream` in C++

For now there are **2 types of files**

- Text
  - Read using `Scanner` class
  - Written using `PrintWriter` class
- Binary
  - Read using `FileInputStream`, `DataInputStream`
  - Written using `FileOutputStream`, `DataOutputStream`

---

## Writing text to file (PrintWriter)

Import libraries

```java
import java.io.*;
```

Create an instance of `PrintWriter` class

```java
// We pass the file name into the constructor
PrintWriter outFile = new PrintWriter("test.txt");
```

Write to file using `print` or `println` methods

```java
outFile.println("Hello how are you?");
```

Closing the file when done

```java
outFile.close();
```

**Note:** `PrintWriter` will throw an `IOException (FileNotFoundException)`

It is a **checked** exception, must be handled!

---

### Prevent File Truncation

Create a `FileWriter` object

```java
FileWriter fw = new FileWriter("test.txt", true);
```

Then create a `PrintWriter` object

```java
PrintWriter outFile = new PrintWriter(fw);
```

---

### PrintWriter Methods

![PrintWriter](Image/PrinterWriter%20Methods.jpg)

---

## Reading Data using Scanner

Create `File` object

```java
File myFile = new File("MyDir/MyText.txt");
```

Create `Scanner` object

```java
Scanner inputFile = new Scanner(myFile);
// Note: FileNotFoundException will be thrown (checked)
```

---

### Scanner Methods

![Scanner Methods](Image/Scanner%20Methods.jpg)

---

### `hasNext()` Method

It is a boolean flag similar to `eof()` in C++

```java
// File processing

while (inputFile.hasNext()) {
    String str = inputFile.nextLine();
    // ....
}

inputFile.close();
```

---

W## Binary Files

Binary I/O does not require encoding/decoding unlike Text I/O

### Binary I/O Classes

![Binary IO Classes](Image/IO%20Classes.jpg)

---

### Binary File Output

`FileOutputStream`

- Allows you to open a file for writing bin. data
- Establishes a connection with the file
- Provides the basic functionality of writing `bytes`

```java
//Constructors
public FileOutputStream(String filename)
public FileOutputStream(File file)
public FileOutputStream(String filename, boolean append)
public FileOutputStream(File file, boolean append)

// A new will be created if it does not exist in the first place
```

`DataOutputStream`

- Allows to write any primitive type or `String` to bin. file
- Used with the above (acts as a wrapper)

```java
FileOutputStream fstream = new FileOutputStream("MyInfo.dat");
DataOutputStream dstream = new DataOutputStream(fstream);

dstream.wrtieInt(7);
dstream.writeDouble(7.5);
dstream.writeChar('m');
dstream.writeChars("This is a test");
dstream.writeUTF("This is a test"); //UTF-8
dstream.writeBoolean(false);
dstream.writeByte(7);
```

---

### Binary File Input

`FileInputStream`

```java
//Constructors
public FileInputStream(String filename)
public FileInputStream(File file)
```

**Note:** `FileNotFoundException` might occur, must handle

`DataInputStream`

Acts as a wrapper around the above class

```java
FileInputStream fstream = new FileInputStream("MyInfo.dat");
DataInputStream dstream = new DataInputStream(fstream)

// Reading primitive types
int i = dstream.readInt();
double d = dstream.readDouble();
char c = dstream.readChar();
String s = dstream.readUTF();
boolean bo = dstream.readBoolean();
byte b = dstream.readByte();
```

#### Reminders for Bin. IO

If you had written to file using `writeUTF()`, then you must read using `readUTF()`

Checing for EOF using the `EOFException`

```java
while  (continueReading) {
    try {
        numbers = dstream.readInt();
    } catch (EOFException e) {
        continueReading = false;
    }
}
```
