#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};
struct Node* add_beg(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->link = head;
    head = newNode;
    return head;
}
void display(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
struct Node* del_beg(struct Node* head){
    struct Node* ptr;
    ptr = head;
    ptr = ptr->link;
    head = ptr;
    return head;
    
}
int main() {
    struct Node* head = NULL;

    // Adding nodes to the linked list
    head = add_beg(head, 2);
    head = add_beg(head, 1);
    head = add_beg(head, 0);
    head = del_beg(head);
   

    // Display the linked list
    display(head);

    return 0;
}