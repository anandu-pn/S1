#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
void shortpath(int parent[],int j){
    if(parent[j]==-1){
        printf("%d ->",j);
        return;
    }
    shortpath(parent,parent[j]);
    printf("%d ->",j);
}
void djistras(int n,int g[n][n],int source){
    int visit[n];
    int dist[n];
    int parent[n];
    for (int i = 0; i < n; i++) { 
        visit[i] = 0;
        dist[i]=INT_MAX;
        parent[i]=-1;
        }
    dist[source]=0;
    for(int count=0;count<n-1;count++){
        int u=-1,v;
        int min=INT_MAX;
        for(int i=0;i<n;i++){
        if(visit[i]==0 && dist[i]<min){
            min=dist[i];
            u=i;
        }
        if (u == -1) { 
            break; }
        visit[u]=1;
        for(v=0;v<n;v++){
            if(!(visit[v]) && dist[u]!=INT_MAX && g[u][v]!=0 && dist[u]+g[u][v]<dist[v]){
                dist[v]=dist[u]+g[u][v];
                parent[v]=u;
            }
        }
    }
    }
    printf("shortest distance:\n");
    for(int i=0;i<n;i++){
        printf("%d \t %d\n",i,dist[i]);
        shortpath(parent,i);
        printf("\n");
    }
   
}
int main(){
    int n,j,i,source;
    printf("Enter the number of node:");
    scanf("%d",&n);
    int g[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("\nEnter the the edge %d %d:",i,j);
            scanf("%d",&g[i][j]);
        }
    }
    printf("\nEmter the source node:");
    scanf("%d",&source);
    djistras(n,g,source);
}
/*
The `parent` array in Dijkstra's algorithm is used to keep track of the predecessor of each vertex in the shortest path tree. This array helps you reconstruct the shortest path from the source vertex to any other vertex in the graph. Here's how it works:

1. **Initialization**: The `parent` array is initialized with `-1` for all vertices, indicating that no vertex has a predecessor initially.

2. **Updating the Parent Array**: During the algorithm's execution, whenever a shorter path to a vertex `v` is found through a vertex `u`, the `parent` array is updated to reflect this. Specifically, `parent[v]` is set to `u`, indicating that the predecessor of vertex `v` in the shortest path is vertex `u`.

3. **Reconstructing the Path**: After the algorithm has finished, you can use the `parent` array to reconstruct the shortest path from the source vertex to any other vertex. Starting from the destination vertex, you can follow the predecessors in the `parent` array until you reach the source vertex.

Here's a step-by-step example to illustrate how the `parent` array works:

### Example Graph
Consider a graph with 4 nodes and the following edges with weights:

```
    (0)
   / | \
  1  4  2
 /   |   \
(1)  3  (2)
 \   |   /
  6  5  8
   \ | /
    (3)
```

### Adjacency Matrix Representation
The graph can be represented using an adjacency matrix as follows:

```
    0  1  2  3
0 [ 0, 1, 4, 2 ]
1 [ 1, 0, 3, 6 ]
2 [ 4, 3, 0, 5 ]
3 [ 2, 6, 5, 0 ]
```

### Dijkstra's Algorithm Execution
Let's assume the source node is `0`. The algorithm will find the shortest path from node `0` to all other nodes.

1. **Initialization**:
   - Distance array: `[0, ∞, ∞, ∞]`
   - Parent array: `[-1, -1, -1, -1]`
   - Visited array: `[0, 0, 0, 0]`

2. **Iteration 1**:
   - Pick node `0` (distance `0`).
   - Update distances: `[0, 1, 4, 2]`
   - Update parents: `[-1, 0, 0, 0]`
   - Mark node `0` as visited: `[1, 0, 0, 0]`

3. **Iteration 2**:
   - Pick node `1` (distance `1`).
   - Update distances: `[0, 1, 4, 2]` (no change)
   - Update parents: `[-1, 0, 0, 0]` (no change)
   - Mark node `1` as visited: `[1, 1, 0, 0]`

4. **Iteration 3**:
   - Pick node `3` (distance `2`).
   - Update distances: `[0, 1, 4, 2]` (no change)
   - Update parents: `[-1, 0, 0, 0]` (no change)
   - Mark node `3` as visited: `[1, 1, 0, 1]`

5. **Iteration 4**:
   - Pick node `2` (distance `4`).
   - Update distances: `[0, 1, 4, 2]` (no change)
   - Update parents: `[-1, 0, 0, 0]` (no change)
   - Mark node `2` as visited: `[1, 1, 1, 1]`

### Final Output
The shortest distances from the source node `0` to all other nodes are:
- Distance to node `0`: `0`
- Distance to node `1`: `1`
- Distance to node `2`: `4`
- Distance to node `3`: `2`

The `parent` array helps you reconstruct the shortest path. For example, to find the path from node `0` to node `2`, you can follow the `parent` array:
- Start at node `2`, parent is `0`
- Path: `0 -> 2`

If you have any more questions or need further assistance, feel free to ask!
*/