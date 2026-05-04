#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high+1;

    while(1){
        do{
            i++;
        }while(i<=high && arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>j){
            break;
        }
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quickSort(int arr[],int low, int high){
    if(low<high){
        int j=partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}
int main(){
    int n;
    printf("enter no. of elements\n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i] = rand() % 100000; 
    }
    clock_t start=clock();
    quickSort(arr,0,n-1);
    clock_t end =clock();
     double time=(double)(end-start)/CLOCKS_PER_SEC;
     //for(int i=0;i<n;i++){
       // printf("%d\t",arr[i]);
    //}
    printf("time taken %f",time);
    free(arr);
    return 0;
}