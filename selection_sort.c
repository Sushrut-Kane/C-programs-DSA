#include <stdio.h>
void selection(int arr[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int main(){
    int arr[10]={5,2,8,1,9,3,6,8,4,10};
    selection(arr,10);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}