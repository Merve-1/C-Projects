# Simple Database (SDB) Project

## Introduction
This project, named Simple Database (SDB), is designed to manage a database of student information. It includes functionality to add new entries, delete entries, read student data, get the list of student IDs, check if a student ID exists, and determine if the database is full. The project is divided into three main files: `SDB.h`, `SDB.c`, and `SDBAPP.c`, with supporting header file `STD.h` and a `main.c` file.

## Files

### 1. `SDB.h`
This file defines the necessary structures, constants, and function prototypes for the Simple Database.

#### Constants
- `MAX_STUDENTS`: Maximum number of students the database can hold.
- `MIN_STUDENTS`: Minimum number of students required for the database to be considered initialized.

#### Structures
- `student`: Structure representing a student's information, including ID, year, and grades for three courses.

#### Function Prototypes
- `bool SDB_IsFull()`: Check if the database is full.
- `uint8 SDB_GetUsedSize()`: Get the number of used entries in the database.
- `bool SDB_AddEntry()`: Add a new entry to the database.
- `void SDB_DeleteEntry(uint32 id)`: Delete an entry from the database based on the student ID.
- `bool SDB_ReadEntry(uint32 id)`: Read and print the details of a student based on their ID.
- `void SDB_GetList(uint8 *count, uint32 *list)`: Get a list of student IDs in the database.
- `bool SDB_IsIdExist(uint32 id)`: Check if a given student ID exists in the database.

### 2. `SDB.c`
This file contains the implementation of the functions declared in `SDB.h`. It manages the array of student data and provides functions for adding, deleting, and querying entries.

### 3. `SDBAPP.c`
This file implements a simple interactive application to interact with the Simple Database. It provides a menu for the user to perform various actions like adding entries, deleting entries, reading student data, and checking database status.

### 4. `STD.h`
This header file defines standard types such as `uint8`, `Int8`, `uint16`, `int16`, `uint32`, `int32`, and `bool` to ensure portability and readability across the project.

### 5. `main.c`
The main entry point of the program. It includes the `SDB_APP()` function, initiating the Simple Database application.

## Usage
To use the Simple Database application, compile all source files and run the executable. Follow the on-screen instructions to perform various actions on the student database.

## Dependencies
- The project relies on the `stdio.h` and custom `STD.h` header files.

