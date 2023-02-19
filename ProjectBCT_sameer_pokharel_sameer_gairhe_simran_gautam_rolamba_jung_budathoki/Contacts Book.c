#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100

// Define a structure for a contact
struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    struct Contact* next;
};

// Declare global variables for the head and tail of the linked list
struct Contact* head = NULL;
struct Contact* tail = NULL;

// Declare function prototypes
void displayMenu();
void addContact();
void deleteContact();
void searchContact();
void displayContacts();

int main() {
    int choice;
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 5);
    return 0;
}

// Display the menu options
void displayMenu() {
    printf("\nContact Book\n");
    printf("1. Add contact\n");
    printf("2. Delete contact\n");
    printf("3. Search contact\n");
    printf("4. Display contacts\n");
    printf("5. Exit\n");
}

// Add a contact to the end of the linked list
void addContact() {
    // Check if the linked list is already full (has 10 contacts)
    if (tail != NULL && tail - head + 1 == 10) {
        printf("\nThe contact book is full. Delete a contact to add a new one.\n");
        return;
    }

    // Create a new contact
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));

    // Get the contact information from the user
    printf("\nEnter the name: ");
    scanf("%s", newContact->name);
    printf("Enter the phone number: ");
    scanf("%s", newContact->phone);
    printf("Enter the email address: ");
    scanf("%s", newContact->email);

    // Set the next pointer of the new contact to NULL
    newContact->next = NULL;

    // Add the new contact to the end of the linked list
    if (head == NULL) {
        head = newContact;
        tail = newContact;
    } else {
        tail->next = newContact;
        tail = newContact;
    }

    printf("\nContact added successfully.\n");
}

// Delete a contact from the linked list
void deleteContact() {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("\nThe contact book is empty. Nothing to delete.\n");
        return;
    }

    // Get the name of the contact to delete from the user
    char nameToDelete[MAX_NAME_LEN];
    printf("\nEnter the name of the contact to delete: ");
    scanf("%s", nameToDelete);

    // Search for the contact in the linked list
    struct Contact* currentContact = head;
    struct Contact* prevContact = NULL;
    // Loop through the linked list until the end or the contact is found
while (currentContact != NULL && strcmp(currentContact->name, nameToDelete) != 0) {
    prevContact = currentContact;
    currentContact = currentContact->next;
}

// If the contact is not found, display an error message
if (currentContact == NULL) {
    printf("\nContact not found.\n");
    return;
}

// Remove the contact from the linked list
if (prevContact == NULL) {
    head = currentContact->next;
} else {
    prevContact->next = currentContact->next;
}
if (currentContact == tail) {
    tail = prevContact;
}

// Free the memory used by the deleted contact
free(currentContact);

printf("\nContact deleted successfully.\n");
}

// Search for a contact in the linked list
void searchContact() {
// Check if the linked list is empty
if (head == NULL) {
printf("\nThe contact book is empty. Nothing to search.\n");
return;
}
// Get the name of the contact to search for from the user
char nameToSearch[MAX_NAME_LEN];
printf("\nEnter the name of the contact to search for: ");
scanf("%s", nameToSearch);

// Search for the contact in the linked list
struct Contact* currentContact = head;
while (currentContact != NULL && strcmp(currentContact->name, nameToSearch) != 0) {
    currentContact = currentContact->next;
}

// If the contact is not found, display an error message
if (currentContact == NULL) {
    printf("\nContact not found.\n");
    return;
}

// Display the contact information
printf("\nName: %s\n", currentContact->name);
printf("Phone number: %s\n", currentContact->phone);
printf("Email address: %s\n", currentContact->email);
}

// Display all contacts in the linked list
void displayContacts() {
// Check if the linked list is empty
if (head == NULL) {
printf("\nThe contact book is empty. Nothing to display.\n");
return;
}
// Display the header for the contact list
printf("\n%-20s %-20s %-20s\n", "Name", "Phone Number", "Email Address");
printf("-----------------------------------------------------------\n");

// Loop through the linked list and display each contact
struct Contact* currentContact = head;
while (currentContact != NULL) {
    printf("%-20s %-20s %-20s\n", currentContact->name, currentContact->phone, currentContact->email);
    currentContact = currentContact->next;
}
}


