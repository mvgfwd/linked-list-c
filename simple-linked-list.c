#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaration of node's structure
struct Node {
    int employeeId;
    char nama[100];
    char tempatLahir[100];
    char tanggalLahir[100];
    char jabatan[100];
    struct Node* ref;
};

//Function to define all the node's data
struct Node* inputNode(struct Node* headRef, int employeeId, char nama[], char tempatLahir[], char tanggalLahir[], char jabatan[]) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->employeeId = employeeId;
    strcpy(newNode->nama, nama);
    strcpy(newNode->tempatLahir, tempatLahir);
    strcpy(newNode->tanggalLahir, tanggalLahir);
    strcpy(newNode->jabatan, jabatan);
    
    // Check if the list is empty
    if (headRef == NULL) {
        headRef = newNode;
    }
    else {
        newNode->ref = headRef;
        headRef = newNode;
    }

    return headRef;
}

//Function to display to console
void tampilkanNode(struct Node* head) {
    struct Node* temporary = head;

    // Traverse the list and print the data of each node
    while (temporary != NULL) {
        printf("Employee ID: %d ", temporary->employeeId);
        printf("Full Name: %s ", temporary->nama);
        printf("Place of Birth: %s ", temporary->tempatLahir);
        printf("Date of Birth: %s ", temporary->tanggalLahir);
        printf("Jabatan: %s ", temporary->jabatan);
        temporary = temporary->ref;
        printf("\n");
    }
}

//C Main function
int main() {
    struct Node* nodenya = NULL;

    // Insert nodes into the linked list
    nodenya = inputNode(nodenya, 31, "Budi Smith", "Jakarta", "12 November 1999", "Admin");
    nodenya = inputNode(nodenya, 42, "Arif Frankenstein", "Bandung", "13 Juni 1998", "Supervisor");
    nodenya = inputNode(nodenya, 68, "Fuad Morrist", "Bandung", "13 Juni 1998", "Manager");


    // Display the linked list
    tampilkanNode(nodenya);

    return 0;
}