#include<stdio.h>
#include<time.h>
struct Item
{
    int weight;
    int profit;
    float ratio;
};
void swap(struct Item *a , struct Item *b){
    struct Item temp=*a ;
    *a=*b;
    *b=temp;
};
void SortbyRatio(struct Item arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].ratio<arr[j+1].ratio){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void SortbyProfit(struct Item arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].profit<arr[j+1].profit){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void SortbyWeight(struct Item arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].weight<arr[j+1].weight){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
float knapsack(struct Item arr[],int n ,int capacity){
    float totalProfit=0;
    for(int i=0;i<n;i++){
        if(capacity>=arr[i].weight){
            totalProfit+=arr[i].profit;
            capacity-=arr[i].weight;
        }else{
            totalProfit+=arr[i].ratio*capacity;
            break;
        }
 
    }
    return totalProfit;
}

int main(){
    int n , capacity, choice;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    printf("Enter weights:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i].weight);
    }

    printf("Enter profits:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i].profit);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    printf("choose a.p/w (optimal) b. profit c,weight\n");
    scanf("%d",&choice);
    clock_t start = clock();
    switch(choice){
        case 1: SortbyRatio(arr,n);
        printf("Optimal method\n");
        break;
        case 2: SortbyProfit(arr,n);
        printf("By profit\n");
        break;
        case 3: SortbyWeight(arr,n);
        printf("By weight \n");
        break;
        default: printf("Invalid choice\n");
        break;
    }
    float maxProfit=knapsack(arr, n, capacity);
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("Max Profit: %.2f\n",maxProfit);
printf("execution time : %f seconds \n",time_taken);
return 0;
}

