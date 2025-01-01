#include<stdio.h>
#include<stdlib.h>
int n,e;
int main(){
    int i;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter number of edges:");
    scanf("%d",&e);
    for(i=0;i<e;e++){
        printf("\nEnter the edge %d",i);
        scanf("")
    }

return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];
int n, e;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal() {
    int i, j, u, v;
    Edge temp;
    int mincost = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("Edges in the minimum spanning tree:\n");
    for (i = 0; i < e; i++) {
        u = find(edges[i].u);
        v = find(edges[i].v);
        if (u != v) {
            printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].w);
            mincost += edges[i].w;
            union1(u, v);
        }
    }
    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int i;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v w):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal();

    return 0;
}

*/