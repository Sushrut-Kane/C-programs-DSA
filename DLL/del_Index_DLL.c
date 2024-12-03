#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete the node at a specific index
struct Node* del_index(struct Node* head, int index) {
    if (head == NULL || index < 0) {
        return head; // Invalid index or empty list
    }
    
    struct Node* ptr = head;
    
    // Traverse to the node at the specified index
    for (int i = 0; ptr != NULL && i < index; i++) {
        ptr = ptr->next;
    }
    
    // If index is out of bounds
    if (ptr == NULL) {
        return head;
    }
    
    // Update pointers to remove the node
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    } else {
        head = ptr->next; // Deleting the head node
    }
    
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    
    free(ptr);  // Free the node at the specified index
    
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
    head = add_beg(head, 4);
    
    printf("Before deletion at index 2: ");
    display(head);
    
    head = del_index(head, 2);
    
    printf("After deletion at index 2: ");
    display(head);
    
    return 0;
}
