#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

// Function to add a node at the beginning of the doubly linked list
struct Node* add_beg(struct Node* head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL; 
    newNode->next = head;

    // Update the previous head's `prev` pointer, if it exists
    if (head != NULL) {
        head->prev = newNode;
    }

    // Update the head pointer
    head = newNode;

    return head;
}


void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;  // Move to the next node
    }
    printf("\n");
}

struct Node* add_end(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
   
    if (head == NULL) {
        newNode->prev = NULL;
        return newNode; 
    }

    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    
    ptr->next = newNode;
    newNode->prev = ptr;

    return head;
}


int main() {
    struct Node* head = NULL;

    // Adding nodes to the linked list
    head = add_beg(head, 2);
    head = add_beg(head, 1);
    head = add_beg(head, 0);
    head = add_end(head,3);

    // Display the linked list
    display(head);

    return 0;
}