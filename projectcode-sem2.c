#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
    char street[50], city[50], state[50], pincode[10];
};

struct Customer {
    char name[50], ssn[20], dob[20], maritalStatus[20], accountNumber[20], accountType[20];
    struct Address address;
    struct Customer* left, *right;
};

struct Customer* root = NULL;

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
    newCustomer->left = newCustomer->right = NULL;
    return newCustomer;
}

struct Customer* insert(struct Customer* root, struct Customer* newCustomer) {
    if (root == NULL) return newCustomer;
    if (strcmp(newCustomer->ssn, root->ssn) < 0)
        root->left = insert(root->left, newCustomer);
    else if (strcmp(newCustomer->ssn, root->ssn) > 0)
        root->right = insert(root->right, newCustomer);
    return root;
}

void saveToFile(struct Customer* root) {
    if (root == NULL) return;
    FILE* file = fopen("bank_records.dat", "ab");
    if (file != NULL) {
        fwrite(root, sizeof(struct Customer), 1, file);
        fclose(file);
    }
    saveToFile(root->left);
    saveToFile(root->right);
}

void searchBySSN(struct Customer* root, char* ssn) {
    if (root == NULL) return;
    if (strcmp(ssn, root->ssn) == 0) {
        printf("Customer Found: %s, SSN: %s\n", root->name, root->ssn);
        return;
    }
    if (strcmp(ssn, root->ssn) < 0) searchBySSN(root->left, ssn);
    else searchBySSN(root->right, ssn);
}

struct Customer* deleteCustomer(struct Customer* root, char* ssn) {
    if (root == NULL) return root;
    if (strcmp(ssn, root->ssn) < 0) root->left = deleteCustomer(root->left, ssn);
    else if (strcmp(ssn, root->ssn) > 0) root->right = deleteCustomer(root->right, ssn);
    else {
        if (root->left == NULL) {
            struct Customer* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Customer* temp = root->left;
            free(root);
            return temp;
        }
        struct Customer* temp = root->right;
        while (temp && temp->left) temp = temp->left;
        strcpy(root->ssn, temp->ssn);
        root->right = deleteCustomer(root->right, temp->ssn);
    }
    return root;
}

void updateRecord(struct Customer* root, char* ssn) {
    if (root == NULL) return;
    if (strcmp(ssn, root->ssn) == 0) {
        printf("Updating customer record...\n");
        printf("Enter new Name: ");
        scanf(" %[^\n]", root->name);
        printf("Enter new Address (Street, City, State, Pincode): ");
        scanf(" %[^\n] %[^\n] %[^\n] %[^\n]", root->address.street, root->address.city, root->address.state, root->address.pincode);
        printf("Enter new Date of Birth: ");
        scanf(" %[^\n]", root->dob);
        printf("Enter new Marital Status: ");
        scanf(" %[^\n]", root->maritalStatus);
        printf("Enter new Account Number: ");
        scanf(" %[^\n]", root->accountNumber);
        printf("Enter new Account Type: ");
        scanf(" %[^\n]", root->accountType);
    }
    else if (strcmp(ssn, root->ssn) < 0) updateRecord(root->left, ssn);
    else updateRecord(root->right, ssn);
}

void menu() {
    int choice;
    char ssn[20];
    struct Customer* newCustomer;
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
                newCustomer = createCustomer();
                root = insert(root, newCustomer);
                saveToFile(root);
                break;
            case 2:
                printf("Enter SSN to search: ");
                scanf(" %[^\n]", ssn);
                searchBySSN(root, ssn);
                break;
            case 3:
                printf("Enter SSN to update: ");
                scanf(" %[^\n]", ssn);
                updateRecord(root, ssn);
                break;
            case 4:
                printf("Enter SSN to delete: ");
                scanf(" %[^\n]", ssn);
                root = deleteCustomer(root, ssn);
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
