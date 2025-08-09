#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

#define V 9 // Number of vertices in the graph

// A utility function to find the vertex with the minimum distance value,
// from the set of vertices not yet included in the shortest path tree.
int minDistance(const std::vector<int>& dist, const std::vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(const std::vector<std::vector<int>>& graph, int src) {
    std::vector<int> dist(V, INT_MAX);
    std::vector<bool> sptSet(V, false);

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not in sptSet, there is an edge from u to v,
            // and total weight of path from src to v through u is smaller than current dist[v].
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    std::cout << "Vertex\t\tDistance from Source" << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << i << "\t\t" << dist[i] << std::endl;
    }
}

// Driver code to test the above function
int main() {
    // Example graph represented as an adjacency matrix
    std::vector<std::vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}