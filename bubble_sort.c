#include <stdio.h>
void bubble(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
    int arr[10]={5,2,8,1,9,3,6,8,4,10};
    bubble(arr,10);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}