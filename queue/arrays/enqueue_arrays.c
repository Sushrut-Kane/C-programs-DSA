#include <stdio.h>
int f=-1;
int r=-1;
#define MAX 5
int arr[MAX];
void enqueue(int data){
    if(f==-1){
        f=f+1;
    }
    r =r+1;
    arr[r] = data;
}
void display(){
    for(int i=f;i<=r;i++){
        printf("%d ",arr[i]);
    }
}
int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
  
    display();
    return 0;
}
