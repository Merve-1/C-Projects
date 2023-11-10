#include "SDB.h" // Include the header file for the student database functions
#include <stdio.h>

// Function to perform actions based on user choice
void SDB_action(uint8 choice) {
  if (choice == 1) {
    // Option 1: Add a new entry to the database
    if (SDB_AddEntry())
      printf("Entry added successfully.\n");
    else
      printf("Database is full, cannot add more entries.\n");
  } else if (choice == 2) {
    // Option 2: Get and display the used size in the database
    printf("Used size in database: %hhu\n", SDB_GetUsedSize());
  } else if (choice == 3) {
    // Option 3: Read and print student data based on the provided ID
    uint32 id;
    printf("Enter student ID: ");
    scanf("%u", &id);
    if (SDB_ReadEntry(id))
      printf("Student data found.\n");
    else
      printf("Student data not found.\n");
  } else if (choice == 4) {
    // Option 4: Get a list of all student IDs in the database
    uint8 count = 0;
    uint32 list[MAX_STUDENTS];

    SDB_GetList(&count, list);

    printf("List of all student IDs:\n");
    for (uint8 i = 0; i < count; i++) {
      printf("%u\n", list[i]);
    }
  } else if (choice == 5) {
    // Option 5: Check if the provided student ID exists in the database
    uint32 id;
    printf("Enter student ID: ");
    scanf("%u", &id);
    if (SDB_IsIdExist(id))
      printf("ID exists in the database.\n");
    else
      printf("ID not found in the database.\n");
  } else if (choice == 6) {
    // Option 6: Delete student data based on the provided ID
    uint32 id;
    printf("Enter student ID to delete: ");
    scanf("%u", &id);
    SDB_DeleteEntry(id);
    printf("Student data deleted.\n");
  } else if (choice == 7) {
    // Option 7: Check if the database is full
    if (SDB_IsFull())
      printf("The database is full.\n");
    else
      printf("The database is not full.\n");
  } else if (choice == 0) {
    // Option 0: Exit the program
    printf("Exiting...\n"); exit(0);
  } else {
    // Invalid choice
    printf("Invalid choice. Please try again.\n");
  }

  printf("\n");
}

// Function to manage the student database application
void SDB_APP() {
  uint8 choice;

  while (1) {
    // Display menu options for the user
    printf("1. To add an entry, enter 1\n");
    printf("2. To get used size in the database, enter 2\n");
    printf("3. To read student data, enter 3\n");
    printf("4. To get the list of all student IDs, enter 4\n");
    printf("5. To check if ID exists, enter 5\n");
    printf("6. To delete student data, enter 6\n");
    printf("7. To check if the database is full, enter 7\n");
    printf("8. To exit, enter 0\n");
    printf("Enter your choice: ");
    scanf("%hhu", &choice);

    // Perform actions based on the user's choice
    SDB_action(choice);
  }
}
