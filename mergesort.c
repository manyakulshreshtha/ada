#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c[100000];
void merge(int a[],int l,int m, int h){
    int i=l,j=m+1,k=l;
    while(i<=m && j<=h){
        if(a[i]<a[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=a[j++];
        }
    }
    while(i<=m){
        c[k++]=a[i++];
    }
    while(j<=h){
        c[k++]=a[j++];
    }
    for(i=0;i<=h;i++){
        a[i]=c[i];
    }
}
void mergeSort(int a[],int l, int h){
    int m;
    if(l<h){
        m=(l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,l,m,h);
    }
}
int main(){
    int n;
    clock_t start, end;
    printf("enter no. of elements\n");
    scanf("%d",&n);
    int *a = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i] = rand() % 100000; 
    }
    start=clock();
    mergeSort(a,0,n-1);
    end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    //for(int i=0;i<n;i++){
      //  printf("%d\t",a[i]);
    //}1
    printf("time taken %f",time);
    free(a);
    return 0;
}