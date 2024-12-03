#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete the node at the end
struct Node* del_end(struct Node* head) {
    if (head == NULL) {
        return NULL; // List is empty
    }
    
    struct Node* ptr = head;
    
    // Traverse to the last node
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    
    // If there's only one node in the list
    if (ptr->prev == NULL) {
        free(ptr);
        return NULL;
    }
    
    // Update the second last node's next pointer to NULL
    ptr->prev->next = NULL;
    free(ptr);  // Free the last node
    
    return head;
}

// Function to display the list
void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to add a node at the beginning of the list
struct Node* add_beg(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    
    head = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    
    head = add_beg(head, 1);
    head = add_beg(head, 2);
    head = add_beg(head, 3);
    
    printf("Before deletion at the end: ");
    display(head);
    
    head = del_end(head);
    
    printf("After deletion at the end: ");
    display(head);
    
    return 0;
}
