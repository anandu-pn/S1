#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void main(){
    int n;
    //The array V[] is initialized to 0 for all nodes, indicating that no nodes have been included in the MST initially.
    int visit[100]={0};
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int g[n][n];
    //adjacensy matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("Enter the weight of edge %d %d: ",i,j);
            scanf("%d",&g[i][j]);
            if (!g[i][j])
               g[i][j] = INT_MAX;
    }
}
    int e=0,cost=0;
    visit[0] = 1; // Starting with the first node
    while(e<n-1){
        int min, u, v;
        for(int i=0;i<n;i++){
            min=INT_MAX;
            if(visit[i]){
            for(int j=0;j<n;j++){
                if(g[i][i] < min && visit[j]==0){
                    min = g[i][j];
                    u = i;
                    v = j;
                }
            }
        }
    }
    visit[v]=1;
    printf("{%d , %d= %d}\n",u,v,min);
    cost+=min;
    e++;

}
    printf("minimum cost %d\n",cost);
}