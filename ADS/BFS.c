#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,size=100;
int que[100];
void enque(int source,int n){
    if(rear==n-1){
        return; }
    if (front==-1) {
        front = 0;
        }
    rear++;
    que[rear]=source;
    
}
int deque(){
    if(front==-1 || front > rear)
    return -1;
    front++;
    return que[front-1];
}
int bfs(int n,int g[n][n],int v[],int source){
    int k=n;
    enque(source,k);
    v[source]=1;
    while(front<=rear){
        int node=deque();
        printf("-> %d ",node);
        for(int i=0;i<n;i++){
            if(g[node][i]!=0 && v[i]==0){
                enque(i,k);
                v[i]=1;
            }

    }

}
}
int main(){
    int n,i,j,source;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    int v[n];
    for(i=0;i<n;i++){
        v[i]=0;
    }
    //adjacency matrix
    int g[n][n];
    for(i=0;i<n;i++){
       printf("\nNext row");
       for(j=0;j<n;j++){
        printf("\nEnter the edge between vertex %d and %d: ",i,j);
        scanf("%d",&g[i][j]);
    }
    }
    //input source
    printf("\nEnter the source node :");
    scanf("%d",&source);
    if(source<0 || source>n){
        printf("invlid source");
        return 0;
    }
    printf("BFS");
    bfs(n,g,v,source);
    return 0;
}