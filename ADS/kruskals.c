#include<stdio.h>
#include<stdlib.h>

int main(){
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
            if (g[i][j]==0)
            //giving max values to all zero weight so as to ignore it
               g[i][j] = INT_MAX;
    }
}
return 0;
}