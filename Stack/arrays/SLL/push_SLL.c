#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* top=NULL;

struct Node* push(struct Node* top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
    return top;
}
void display(struct Node* top) {
    struct Node* ptr = top;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
int main(){
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    top=push(top,4);
    
  
    display(top);
    return 0;
}
