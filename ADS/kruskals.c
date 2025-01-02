#include<stdio.h>
#include<stdlib.h>
int n,e,parent[100];
typedef struct{
    int u,v,w;
}edge;
//find and union are operation in disjoint set data structure
int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}
void Union (int U,int V){
    int p1,p2;
    p1=find(U);
    p2=find(V);
    parent[p1]=p2;
}

edge Edges[100];
void kruskals(){
    int j,i,U,V;
    int mincost=0;
    edge temp;
    for(i=0;i<n;i++){
        parent[i]=i;
    }
//to order by weight
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e -1; j++) {
            if (Edges[j].w > Edges[j + 1].w || (Edges[j].w == Edges[j + 1].w && Edges[j].u > Edges[j + 1].u)) {
                temp = Edges[j];
                Edges[j] = Edges[j + 1];
                Edges[j + 1] = temp;
            }
        }
    }
    for(i=0;i<e;i++){
        printf("{%d - %d = %d}\n",Edges[i].u,Edges[i].v,Edges[i].w);
    }
    printf("\nminimum spanning tree:\n");
//we need to check weher there are any closed edges
    for(i=0;i<e;i++){
        U=find(Edges[i].u);
        V=find(Edges[i].v);
        if(U!=V){
            printf("{%d - %d = %d}\n",Edges[i].u,Edges[i].v,Edges[i].w);
            mincost+=Edges[i].w;
            Union(Edges[i].u,Edges[i].v);
        }
        printf("Parent array after processing edge {%d - %d = %d}: ", Edges[i].u, Edges[i].v, Edges[i].w); 
        for (j = 0; j < n; j++) { 
            printf("%d ", parent[j]); 
            } 
            printf("\n"); 
    }
    printf("Minimum cost = %d\n", mincost);

}

int main(){
    int i;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter number of edges:");
    scanf("%d",&e);
    for(i=0;i<e;i++){
        printf("\nEnter the edge u,v,w :");
        scanf("%d %d %d",&Edges[i].u,&Edges[i].v,&Edges[i].w);
    }
    kruskals();
return 0;
}
