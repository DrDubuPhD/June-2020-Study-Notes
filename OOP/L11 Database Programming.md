# Database Programming

- [Database Programming](#database-programming)
  - [Loading Driver](#loading-driver)
  - [Establishing DB Connection](#establishing-db-connection)
  - [Creating and Executing Statements](#creating-and-executing-statements)
  - [ResultSet Class (Displaying Query Results)](#resultset-class-displaying-query-results)
  - [General Pipeline For DB Programming](#general-pipeline-for-db-programming)
  - [PreparedStatement](#preparedstatement)
  - [DB Metadata](#db-metadata)
    - [DatabaseMetaData Methods](#databasemetadata-methods)
      - [Applying DatabaseMetaData](#applying-databasemetadata)

## Loading Driver

Before connecting to a database, you must first

- **load the driver**

```java
Class.forName("JDBCDriverClass");
```

## Establishing DB Connection

To establish a connection use this method

`DriverManager.getConnection()`

Example:

```java
Connection conn = DriverManager.getConnection(databaseURL); // either relative or remote
```

![DatabaseConnectionProcedures](Image/DB%20Connection.jpg)

## Creating and Executing Statements

We use the methods provided in the `Connection` class

```java
Statement st = conn.createStatement();

// Creating a table
st.executeUpdate("create table <tableName>(<attr1> <datatype>, ... primary key(attr1))");

// Inserting data into the table
st.executeUpdate("insert into <tableName> values(<init. list here>)");

// Updating data
st.executeUpdate("update <tableName> set <attrName> = <newValue> where <attrName> = <newValue>");

// To query results (Important)
ResultSet rs = st.executeQuery("select * from <tableName>"); // Stores in ResultSet (row by row)

// Deleting records
st.executeUpdate("Delete from <tableName> where <attrName> = <value>")
```

## ResultSet Class (Displaying Query Results)

`next()` methods serves 2 purposes

- moves the cursor to the next row
- acts as a boolean flag to check if there are more results

To display the query results we use

```java
int nc = 4 // no. of cols

while(rs.next()) { // EOF Flag

    for (int i = 1; i <= nc; i++) {
        System.out.print(rs.getString(i) + "\t");
    }

    System.out.println();
}

// The while loop controls the rows, while the for loop controls the columns

// Close the DB connection when done

conn.close();
```

---

## General Pipeline For DB Programming

![DBPipeline](Image/DB%20Pipeline.jpg)

---

**Note:** Code for Access Connection

```java
Connection conn = DriverManager.getConnection(".../db1.accdb");

Statement statement = conn.createStatement();

statement.executeUpdate("<SQL code here>");
```

The above pieces of code will throw a checked exception (`SQLException`)

---

## PreparedStatement

`Statement` class is used to execute static statements

`PreparedStatement` is to

- Execute precompiled SQL statement **dynamically**
- Optional Parameters

```java
PreparedStatement pstmt = conn.prepareStatement("insert into <Table> (<attr(s)>) values (?, ?, ...)");
```

The `?` acts as placeholders (tokens)

To set the values of the params:

- `pstmt.setInt(1, 4);`
- `pstmt.setString(2, "Jack");`
- `pstmt.setString(3, "Johor");`
- `pstmt.setString(4, "FBF");`

General pattern is `<PreparedStatementObj>.set<DataType>(<PlaceHolderPos>, <Value>)`

Execute `PreparedStatement` using `pstmt.executeUpdate();`

## DB Metadata

Metadata describes the table

```java
DatabaseMetaData dbMetaData = conn.getMetaData();
```

### DatabaseMetaData Methods

| Method                     | Info                 |
|----------------------------|----------------------|
| `getURL()`                 | DB URL               |
| `getUserName()`            | DB Username          |
| `getDatabaseProductName()` | DB Product Name      |
| `getDriverName()`          | JDBC Driver Name     |
| `getDriverVersion()`       | JDBC Driver Version  |
| `getMaxConnections()`      | Max # of connections |
| `getTables()`              | Refer snippet below  |

```java
ResultSet rsTables = dbMetaData.getTables(null, null, null, new String[]{"Table"});

System.out.println("User Tables: ");

while (rsTables.next())
    System.out.println(rsTables.getString("TABLE_NAME") + " ");
```

#### Applying DatabaseMetaData

```java
// To avoid hard coding this
// int nc = 4 // no. of cols

// We make use of MetaData

ResultSetMetaData rsMetaData = rs.getMetaData();

// Then do this

int nc = rsMetaData.getColumnCount();

while(rs.next()) { // EOF Flag

    for (int i = 1; i <= nc; i++) {
        System.out.print(rs.getObject(i) + "\t");
    }

    System.out.println();
}

// The while loop controls the rows, while the for loop controls the columns

// Close the DB connection when done

conn.close();
```
