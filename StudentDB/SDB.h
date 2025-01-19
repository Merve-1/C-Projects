#include "STD.h" // Include any necessary header files
#define MAX_STUDENTS 10 
// Define the maximum number of students the database can hold
#define MIN_STUDENTS 3 
// Define the minimum number of students required for the database to be considered initialized

// Define the structure for a student
typedef struct SimpleDb {
  uint32 studentId;
  uint32 year;
  uint32 course1Id;
  uint32 course1Grade;
  uint32 course2Id;
  uint32 course2Grade;
  uint32 course3Id;
  uint32 course3Grade;
} student;

// Function prototypes
bool SDB_IsFull(); // Check if the database is full
uint8 SDB_GetUsedSize(); // Get the number of used entries in the database
bool SDB_AddEntry(); // Add a new entry to the database
void SDB_DeleteEntry(uint32 id); // Delete an entry from the database based on the student ID
bool SDB_ReadEntry(uint32 id); // Read and print the details of a student based on their ID
void SDB_GetList(uint8 *count, uint32 *list); // Get a list of student IDs in the database
bool SDB_IsIdExist(uint32 id); // Check if a given student ID exists in the database
