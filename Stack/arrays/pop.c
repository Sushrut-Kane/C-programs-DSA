#include <stdio.h>
#define MAX 5
int arr[MAX];
int top=-1;
void pop(){
    top = top-1;
}
void display(){
    for(int i=top;i>-1;i--){
        printf("%d ",arr[i]);
    }
}

int main(){
    arr[0]  =1;
    arr[1]  =2;
    arr[2]  =3;
    top=2;
    pop();
    display();
    return 0;
}
