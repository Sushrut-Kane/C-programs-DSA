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
void del_index(struct Node* head,  int index){
    struct Node* ptr=head;
    struct Node* ptr1=ptr->link;
    for(int i=0;i<index-1;i++){
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }
    ptr->link = ptr1->link;



}
int main() {
    struct Node* head = NULL;

  
    head = add_beg(head, 2);
    head = add_beg(head, 1);
    head = add_beg(head, 0);

    del_index(head,1);
    display(head);

    return 0;
}