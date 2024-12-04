#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node* n;
    n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int isBST(struct Node* root){
    struct Node* prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return 1;
    }
}
int main(){
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4); 
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    if(isBST){
        printf("Yes");
    }else{
        printf("NO");
    }
    return 0;
}
