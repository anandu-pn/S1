#include<stdio.h>
#include<stdlib.h>
void topdfs(int k,int n,int g[n][n],int visited[n],int stack[n],int *top){
    visited[k]=1;
    for(int i=0;i<n;i++){
        if(g[k][i]!=0 && visited[i]==0){
            topdfs(i,n,g,visited,stack,top);
        }
    }
    //he *top variable is incremented after the value v is assigned to stack[*top]. This is known as the post-increment operation.
    stack[(*top)++]=k;
}
void topologicalSort(int n,int g[n][n]){
    int i,j;
    int visited[n];
    int stack[n];
    int top=0;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0;i<n;i++){
        if(visited[i]==0){
            topdfs(i,n,g,visited,stack,&top);
        }
    }
    printf("\nTopological sort is:");
    for(i=top-1;i>=0;i--){
        printf("%d ->",stack[i]);
    }
}
int main(){
    int n,i,j;
    printf("Enter number of node: ");
    scanf("%d",&n);
    //adjacensy matrix
    int g[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter the node %d %d : ",i,j);
            scanf("%d",&g[i][j]);
        }
    }
    topologicalSort(n,g);
    return 0;
}  