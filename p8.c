#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
    int ssn;
    char name[50];
    char dept[50];
    char designation[50];
    double salary;
    char phone[15];
    struct Employee* prev;
    struct Employee* next;
};

struct Employee* head = NULL;
struct Employee* tail = NULL;
int count = 0;
struct Employee* createNode() {
    struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!");
        return NULL;
    }
    
    printf("\nEnter Employee Details:");
    printf("\nSSN: ");
    scanf("%d", &newNode->ssn);
    printf("Name: ");
    scanf("%s", newNode->name);
    printf("Department: ");
    scanf("%s", newNode->dept);
    printf("Designation: ");
    scanf("%s", newNode->designation);
    printf("Salary: ");
    scanf("%lf", &newNode->salary);
    printf("Phone Number: ");
    scanf("%s", newNode->phone);
    
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createDLL() {
    int n;
    printf("\nEnter number of employees: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        struct Employee* newNode = createNode();
        if (newNode == NULL) return;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }
}
void display() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }
    
    struct Employee* temp = head;
    int nodeCount = 0;
    
    printf("\nDoubly Linked List Status:");
    printf("\nTotal number of nodes: %d", count);
    
    while (temp != NULL) {
        nodeCount++;
        printf("\n\nNode %d Details:", nodeCount);
        printf("\nSSN: %d", temp->ssn);
        printf("\nName: %s", temp->name);
        printf("\nDepartment: %s", temp->dept);
        printf("\nDesignation: %s", temp->designation);
        printf("\nSalary: %.2f", temp->salary);
        printf("\nPhone: %s", temp->phone);
        temp = temp->next;
    }
}
void insertEnd() {
    struct Employee* newNode = createNode();
    if (newNode == NULL) return;
    
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
    printf("\nEmployee inserted successfully at end!");
}
void deleteEnd() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }
    
    struct Employee* temp = tail;
    
    printf("\nDeleted Employee Details:");
    printf("\nSSN: %d", temp->ssn);
    printf("\nName: %s", temp->name);
    
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    
    free(temp);
    count--;
    printf("\nEmployee deleted successfully from end!");
}
void insertFront() {
    struct Employee* newNode = createNode();
    if (newNode == NULL) return;
    
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
    printf("\nEmployee inserted successfully at front!");
}
void deleteFront() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }
    
    struct Employee* temp = head;
    
    printf("\nDeleted Employee Details:");
    printf("\nSSN: %d", temp->ssn);
    printf("\nName: %s", temp->name);
    
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    
    free(temp);
    count--;
    printf("\nEmployee deleted successfully from front!");
}
void demoDeque() {
    int choice;
    
    printf("\nDouble Ended Queue Operations:");
    printf("\n1. Insert at Front (Enqueue Front)");
    printf("\n2. Insert at End (Enqueue Rear)");
    printf("\n3. Delete from Front (Dequeue Front)");
    printf("\n4. Delete from End (Dequeue Rear)");
    printf("\n5. Display Queue");
    printf("\n6. Return to Main Menu");
    
    do {
        printf("\n\nEnter your choice for Queue operation: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nReturning to main menu...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 6);
}

int main() {
    int choice;
    
    printf("\nDoubly Linked List Operations:");
    printf("\n1. Create DLL of N Employees");
    printf("\n2. Display Status and Count Nodes");
    printf("\n3. Insert at End");
    printf("\n4. Delete from End");
    printf("\n5. Insert at Front");
    printf("\n6. Delete from Front");
    printf("\n7. Demonstrate Double Ended Queue");
    printf("\n8. Exit");
    
    do {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                createDLL();
                break;
            case 2:
                display();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                demoDeque();
                break;
            case 8:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 8);
    struct Employee* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}