#include <stdio.h>
void insertion_sort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
            }
        arr[j+1]=key;
    }        
}
int main(){
    int arr[10]={5,2,8,1,9,3,6,8,4,10};
    insertion_sort(arr,10);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}