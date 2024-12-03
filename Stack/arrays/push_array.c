#include <stdio.h>
#define MAX 5
int arr[MAX];
int top=-1;
void push(int data){
    top = top+1;
    arr[top]=data;
}
void display(){
    for(int i=top;i>-1;i--){
        printf("%d ",arr[i]);
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    
  
    display();
    return 0;
}
