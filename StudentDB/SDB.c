#include "SDB.h"
#include <stdio.h>

// Define the structure for a student
student studentsDatabase[MAX_STUDENTS]; // Array to store student data
uint8 usedSize = 0; // Keep track of the number of used entries in the database

// Check if the database is full
bool SDB_IsFull() {
  return usedSize >= MAX_STUDENTS;
}

// Get the number of used entries in the database
uint8 SDB_GetUsedSize() {
  return usedSize;
}

// Add a new entry to the database
bool SDB_AddEntry() {
  if (SDB_IsFull()) {
    return false; // Database is full, cannot add more entries
  }
  else {
    // Prompt user for student details
    uint32 studentId, year, course1Id, course1Grade, course2Id, course2Grade, course3Id, course3Grade;

    // User input for student details
    printf("Enter Student ID: ");
    scanf("%d", &studentId);
    printf("Enter Year: ");
    scanf("%d", &year);
    printf("Enter Course 1 ID: ");
    scanf("%d", &course1Id);
    printf("Enter Course 1 Grade: ");
    scanf("%d", &course1Grade);
    printf("Enter Course 2 ID: ");
    scanf("%d", &course2Id);
    printf("Enter Course 2 Grade: ");
    scanf("%d", &course2Grade);
    printf("Enter Course 3 ID: ");
    scanf("%d", &course3Id);
    printf("Enter Course 3 Grade: ");
    scanf("%d", &course3Grade);

    // Add student to the database
    studentsDatabase[usedSize].studentId = studentId;
    studentsDatabase[usedSize].year = year;
    studentsDatabase[usedSize].course1Id = course1Id;
    studentsDatabase[usedSize].course1Grade = course1Grade;
    studentsDatabase[usedSize].course2Id = course2Id;
    studentsDatabase[usedSize].course2Grade = course2Grade;
    studentsDatabase[usedSize].course3Id = course3Id;
    studentsDatabase[usedSize].course3Grade = course3Grade;

    usedSize++; // Increase the used size of the database
    return true;
  }
}

// Delete an entry from the database based on the student ID
void SDB_DeleteEntry(uint32 studentId) {
  if (usedSize >= MIN_STUDENTS) {
    for (uint8 i = 0; i < usedSize; i++) {
      if (studentsDatabase[i].studentId == studentId) {
        // Shift all entries after this one to the left
        for (uint8 j = i; j < usedSize - 1; j++) {
            studentsDatabase[j] = studentsDatabase[j + 1];
        }
        usedSize--; // Decrease the used size of the database
        break;      // Exit the loop after deleting the entry
      }
    }
  }
  else{
    printf("Your aren't able to delete students if the database doesn't contain at least 3 students");
  }
}

// Read and print the details of a student based on their ID
bool SDB_ReadEntry(uint32 id) {
  // Check if there are at least 3 students in the database before displaying data
  if (usedSize >= MIN_STUDENTS) {
    for (uint8 i = 0; i < usedSize; i++) {
      if (studentsDatabase[i].studentId == id) {
        // Print student details
        printf("Student ID: %u\nYear: %u\nCourse 1 ID: %u\nCourse 1 Grade: %u\nCourse 2 ID: %u\nCourse 2 Grade: %u\nCourse 3 ID: %u\nCourse 3 Grade: %u\n",
            studentsDatabase[i].studentId, studentsDatabase[i].year,
            studentsDatabase[i].course1Id, studentsDatabase[i].course1Grade,
            studentsDatabase[i].course2Id, studentsDatabase[i].course2Grade,
            studentsDatabase[i].course3Id, studentsDatabase[i].course3Grade);
        return true;
      }
    }
  }
  else{
    printf("You aren't able to see the student's data until you have min 3 students in your database");
  }
  return false; // Student data not found or not enough students in the database
}

// Get a list of student IDs in the database
void SDB_GetList(uint8 *count, uint32 *list) {
  // Check if there are at least 3 students in the database before getting the list
  if (usedSize >= MIN_STUDENTS) {
    *count = usedSize;
    for (uint8 i = 0; i < usedSize; i++) {
      list[i] = studentsDatabase[i].studentId;
    }
  } else {
    *count = 0; // Set count to 0 if there are not enough students
    printf("You aren't able to see the student's data until you have min 3 students in your database");
  }
}

// Check if a given student ID exists in the database
bool SDB_IsIdExist(uint32 studentId) {
  for (uint8 i = 0; i < usedSize; i++) {
    if (studentsDatabase[i].studentId == studentId) {
      return true; // ID exists in the database
    }
  }
  return false; // ID not found
}
