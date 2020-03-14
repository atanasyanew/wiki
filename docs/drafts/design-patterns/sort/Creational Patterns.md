# Creational Patterns

│       05 Abstract Factory.flv
│       06 Abstract Factory Example.flv
│       07 Builder.flv
│       08 Builder Example.flv
│       09 Factory Method.flv
│       10 Factory Method Example.flv
│       11 Prototype.flv
│       12 Prototype Example.flv
│       13 Singleton.flv
│       14 Singleton Example.flv

## Abstract Factory Pattern

## Builder Pattern

we want application to have single method to build all configs

- App needs to construct multiple type classes
- These classes have complicated construction methods
- Database
  - Connection string, command type, timeout
- Measurement data sources
  - serial port: port number, baud rate, parity, etc.
  - Ethernet: IP addresses, timeout etc.
- Isolate construction process from application

---

- Builder interface or abstract class
  - Generalized object construction
  - provides methods for each object construction
- Create builder classes that implement builder interface for each object type

---

- Director class
  - Uses Builder class to create object
  - Hides creational details from rest of application

---

- Construct database class
  - SQK server and OleDb
  - Create connection, Command Objects
  - Set Command parameters

Builder pattern example classes

- Database abstract factory classes
- Abstract database class
- SqlServerDatabase class
  - inherit from database class
- OleDbDatabase class
  - inherit from database class

Builder pattern example classes

- IDatabaseBuilder interface
  - BuildConnection method
  - BuildCommand method
  - SetSettings method
  - Database property
- SqlServerDatabaseBuilder and OleDbDatabaseBuilder classes
  - implement IDatabaseBuilder
