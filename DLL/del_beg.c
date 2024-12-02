#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

// Function to delete the first node of the doubly linked list
struct Node* del_beg(struct Node* head) {
    if (head == NULL) return head; // Empty list

    struct Node* temp = head;
    head = head->next; // Move head to the next node
    if (head != NULL) {
        head->prev = NULL; // Update the new head's prev pointer
    }

    free(temp); // Free the memory of the old head
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
