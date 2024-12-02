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

// Function to add a node at a specific index (index is valid, list is long)
struct Node* add_index(struct Node* head, int data, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* ptr = head;
    struct Node* ptr1 = NULL;

    // Traverse to the (index - 1)th node
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
    }

    // Now ptr is pointing to the (index - 1)th node, and ptr1 is the node at index
    ptr1 = ptr->next;

    // Link the new node
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = ptr1;

    // If ptr1 exists, update its prev pointer
    if (ptr1 != NULL) {
        ptr1->prev = newNode;
    }

    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;  // Move to the next node
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Adding nodes to the linked list
    head = add_beg(head, 2);  // List: 2
    head = add_beg(head, 1);  // List: 1 2
    head = add_beg(head, 0);  // List: 0 1 2
    head = add_index(head, 23, 1);  // List: 0 23 1 2

    // Display the linked list
    display(head);

    return 0;
}
