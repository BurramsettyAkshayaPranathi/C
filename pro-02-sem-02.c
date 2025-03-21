#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
    char street[50], city[50], state[50], pincode[10];
};

struct Customer {
    char name[50], ssn[20], dob[20], maritalStatus[20], accountNumber[20], accountType[20];
    struct Address address;
    struct Customer* next;
};

struct Customer* head = NULL;

struct Customer* createCustomer() {
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    printf("Enter Name: ");
    scanf(" %[^\n]", newCustomer->name);
    printf("Enter SSN: ");
    scanf(" %[^\n]", newCustomer->ssn);
    printf("Enter Address (Street, City, State, Pincode): ");
    scanf(" %[^\n] %[^\n] %[^\n] %[^\n]", newCustomer->address.street, newCustomer->address.city, newCustomer->address.state, newCustomer->address.pincode);
    printf("Enter Date of Birth: ");
    scanf(" %[^\n]", newCustomer->dob);
    printf("Enter Marital Status: ");
    scanf(" %[^\n]", newCustomer->maritalStatus);
    printf("Enter Account Number: ");
    scanf(" %[^\n]", newCustomer->accountNumber);
    printf("Enter Account Type: ");
    scanf(" %[^\n]", newCustomer->accountType);
    newCustomer->next = NULL;
    return newCustomer;
}

void insertCustomer() {
    struct Customer* newCustomer = createCustomer();
    if (head == NULL) {
        head = newCustomer;
    } else {
        struct Customer* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }
}

void searchCustomerBySSN(char* ssn) {
    struct Customer* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->ssn, ssn) == 0) {
            printf("Customer Found: %s, SSN: %s\n", temp->name, temp->ssn);
            return;
        }
        temp = temp->next;
    }
    printf("Customer not found.\n");
}

void updateCustomer(char* ssn) {
    struct Customer* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->ssn, ssn) == 0) {
            printf("Updating customer record...\n");
            printf("Enter new Name: ");
            scanf(" %[^\n]", temp->name);
            printf("Enter new Address (Street, City, State, Pincode): ");
            scanf(" %[^\n] %[^\n] %[^\n] %[^\n]", temp->address.street, temp->address.city, temp->address.state, temp->address.pincode);
            printf("Enter new Date of Birth: ");
            scanf(" %[^\n]", temp->dob);
            printf("Enter new Marital Status: ");
            scanf(" %[^\n]", temp->maritalStatus);
            printf("Enter new Account Number: ");
            scanf(" %[^\n]", temp->accountNumber);
            printf("Enter new Account Type: ");
            scanf(" %[^\n]", temp->accountType);
            return;
        }
        temp = temp->next;
    }
    printf("Customer not found.\n");
}

void deleteCustomer(char* ssn) {
    struct Customer* temp = head;
    struct Customer* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->ssn, ssn) == 0) {
            if (prev == NULL) {
                head = temp->next; // Delete the head
            } else {
                prev->next = temp->next; // Delete the node
            }
            free(temp);
            printf("Customer record deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Customer not found.\n");
}

void menu() {
    int choice;
    char ssn[20];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert new customer\n");
        printf("2. Find and display customer by SSN\n");
        printf("3. Update customer record\n");
        printf("4. Delete customer record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertCustomer();
                break;
            case 2:
                printf("Enter SSN to search: ");
                scanf(" %[^\n]", ssn);
                searchCustomerBySSN(ssn);
                break;
            case 3:
                printf("Enter SSN to update: ");
                scanf(" %[^\n]", ssn);
                updateCustomer(ssn);
                break;
            case 4:
                printf("Enter SSN to delete: ");
                scanf(" %[^\n]", ssn);
                deleteCustomer(ssn);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
