#include<stdio.h>
#define MAX 100
#define INF 99999
void floydWarshall(int graph[MAX][MAX],int n){
    int dist[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    printf("All Pairs shortest Path  Matrix \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]==INF){
                printf("INF ");
            }else{
                printf("%d ",dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main(){
    int n,graph[MAX][MAX];
    printf("Enter no. of Vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);}}
    floydWarshall(graph, n);
    return 0;
}