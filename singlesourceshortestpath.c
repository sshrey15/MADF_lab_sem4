#include <stdio.h>
#include <stdbool.h>
#include <float.h>

#define MAX_VERTICES 100

void shortest_paths(int u, float cost[MAX_VERTICES][MAX_VERTICES], int n, float dist[]) {
    bool S[MAX_VERTICES] = {false};
    
    // Initialize distances
    for(int i = 0; i < n; i++) {
        dist[i] = FLT_MAX;
    }
    dist[u] = 0.0;
    S[u] = true;
    
    // Main loop
    for(int num = 2; num < n; num++) {
        // Choose vertex u not in S with minimum dist[u]
        int min_u = -1;
        float min_dist = FLT_MAX;
        for(int i = 0; i < n; i++) {
            if (!S[i] && dist[i] < min_dist) {
                min_u = i;
                min_dist = dist[i];
            }
        }
        if(min_u == -1) break; // No more vertices to explore
        
        S[min_u] = true;
        
        // Update distances for vertices adjacent to u
        for(int w = 0; w < n; w++) {
            if (!S[w] && dist[w] > dist[min_u] + cost[min_u][w]) {
                dist[w] = dist[min_u] + cost[min_u][w];
            }
        }
    }
}

int main() {
    float cost[MAX_VERTICES][MAX_VERTICES] = {
        {0, 10, FLT_MAX, 5},
        {FLT_MAX, 0, 1, 2},
        {FLT_MAX, FLT_MAX, 0, 4},
        {FLT_MAX, 3, 9, 0}
    };
    int source_vertex = 0;
    int num_vertices = 4;
    float shortest_distances[MAX_VERTICES];
    
    shortest_paths(source_vertex, cost, num_vertices, shortest_distances);
    
    printf("Shortest distances from vertex %d:\n", source_vertex);
    for(int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %.2f\n", i, shortest_distances[i]);
    }
     return 0;
}
