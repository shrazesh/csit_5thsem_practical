#include <stdio.h>

#define MAX 100  

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Structure to represent a disjoint set
int parent[MAX], rank[MAX];

// Function to find the root of a set with path compression
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Function to perform union by rank
void union_sets(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);

    if (root_i != root_j) {
        if (rank[root_i] > rank[root_j]) {
            parent[root_j] = root_i;
        } else if (rank[root_i] < rank[root_j]) {
            parent[root_i] = root_j;
        } else {
            parent[root_j] = root_i;
            rank[root_i]++;
        }
    }
}

// Function to implement Kruskal’s algorithm
void kruskal(struct Edge edges[], int n, int e) {
    int i, j, totalWeight;
    struct Edge temp, mst[MAX];

    // Initialize disjoint set
    for (i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight using Bubble Sort (Can be replaced by QuickSort)
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Kruskal’s algorithm
    int edgeCount = 0;
    totalWeight = 0;
    i = 0;

    while (edgeCount < n - 1 && i < e) {
        struct Edge nextEdge = edges[i++];
        int root_u = find(nextEdge.u);
        int root_v = find(nextEdge.v);

        if (root_u != root_v) {  
            mst[edgeCount++] = nextEdge;
            totalWeight += nextEdge.weight;
            union_sets(root_u, root_v);
        }
    }

    // Display the Minimum Spanning Tree with letters
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < edgeCount; i++)
        printf("%c - %c : %d\n", 'A' + mst[i].u, 'A' + mst[i].v, mst[i].weight);
    printf("Total Minimum Cost: %d\n", totalWeight);
}

// Driver Code
int main() {
    int n, e, i;
    printf("\t Kruskal Algorithm \n");
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight) using numbers (0=A, 1=B, etc.):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    kruskal(edges, n, e);
    printf("\t Shrajesh Shrestha \n");

    return 0;
}

