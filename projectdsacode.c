#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[100], ssn[20], street[100], city[50], state[50], pincode[10], date_of_birth[15], marital_status[10], account_number[20], account_type[20];
    struct Customer* next;
};

struct Customer* head = NULL;

void createCustomer() {
    struct Customer* newNode = (struct Customer*)malloc(sizeof(struct Customer));
    printf("Enter customer details:\nName: ");
    scanf(" %99[^\n]", newNode->name);
    printf("SSN: ");
    scanf(" %19s", newNode->ssn);
    printf("Street: ");
    scanf(" %99[^\n]", newNode->street);
    printf("City: ");
    scanf(" %49[^\n]", newNode->city);
    printf("State: ");
    scanf(" %49[^\n]", newNode->state);
    printf("Pincode: ");
    scanf(" %9s", newNode->pincode);
    printf("Date of Birth (dd/mm/yyyy): ");
    scanf(" %14s", newNode->date_of_birth);
    printf("Marital Status: ");
    scanf(" %9s", newNode->marital_status);
    printf("Account Number: ");
    scanf(" %19s", newNode->account_number);
    printf("Account Type: ");
    scanf(" %19s", newNode->account_type);
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        struct Customer* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    printf("Customer record inserted successfully.\n");
}

void findCustomer() {
    char ssn[20];
    printf("Enter SSN to find: ");
    scanf(" %19s", ssn);
    struct Customer* temp = head;
    while (temp) {
        if (strcmp(temp->ssn, ssn) == 0) {
            printf("Customer Found: %s | SSN: %s | Address: %s, %s, %s, %s | DOB: %s | Marital: %s | Account: %s | Type: %s\n",
                temp->name, temp->ssn, temp->street, temp->city, temp->state, temp->pincode, temp->date_of_birth, temp->marital_status, temp->account_number, temp->account_type);
            return;
        }
        temp = temp->next;
    }
    printf("Customer not found.\n");
}

void updateCustomer() {
    char ssn[20];
    printf("Enter SSN to update: ");
    scanf(" %19s", ssn);
    struct Customer* temp = head;
    while (temp) {
        if (strcmp(temp->ssn, ssn) == 0) {
            printf("Update customer details:\nName: ");
            scanf(" %99[^\n]", temp->name);
            printf("Street: ");
            scanf(" %99[^\n]", temp->street);
            printf("City: ");
            scanf(" %49[^\n]", temp->city);
            printf("State: ");
            scanf(" %49[^\n]", temp->state);
            printf("Pincode: ");
            scanf(" %9s", temp->pincode);
            printf("Date of Birth: ");
            scanf(" %14s", temp->date_of_birth);
            printf("Marital Status: ");
            scanf(" %9s", temp->marital_status);
            printf("Account Number: ");
            scanf(" %19s", temp->account_number);
            printf("Account Type: ");
            scanf(" %19s", temp->account_type);
            printf("Customer record updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Customer not found.\n");
}

void deleteCustomer() {
    char ssn[20];
    printf("Enter SSN to delete: ");
    scanf(" %19s", ssn);
    struct Customer *temp = head, *prev = NULL;
    while (temp) {
        if (strcmp(temp->ssn, ssn) == 0) {
            if (!prev) head = temp->next;
            else prev->next = temp->next;
            free(temp);
            printf("Customer record deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Customer not found.\n");
}

void displayCustomers() {
    struct Customer* temp = head;
    if (!temp) { printf("No customers to display.\n"); return; }
    while (temp) {
        printf("Name: %s | SSN: %s | Address: %s, %s, %s, %s | DOB: %s | Marital Status: %s | Account No: %s | Type: %s\n",
               temp->name, temp->ssn, temp->street, temp->city, temp->state, temp->pincode, temp->date_of_birth, temp->marital_status, temp->account_number, temp->account_type);
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        printf("\nBanking System Menu:\n1. Insert new customer\n2. Find customer by SSN\n3. Update customer record\n4. Delete customer record\n5. Display all customers\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: createCustomer(); break;
            case 2: findCustomer(); break;
            case 3: updateCustomer(); break;
            case 4: deleteCustomer(); break;
            case 5: displayCustomers(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);


    struct Customer* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
