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
        exit(1); 
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
struct Node* reverse(struct Node* head){
    struct Node* ptr=NULL;
    struct Node* ptr1=NULL;
    while(head!=NULL){
        //JUST REMEMBER THIS AND YOU ARE DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ptr1 = head->link;
        head->link = ptr;
        ptr = head;
        head = ptr1;
    }
    head = ptr;
    return head;
}
int main() {
    struct Node* head = NULL;

  
    head = add_beg(head, 3);
    head = add_beg(head, 2);
    head = add_beg(head, 1);
    head = add_beg(head, 0);
    head = reverse(head);


    display(head);

    return 0;
}