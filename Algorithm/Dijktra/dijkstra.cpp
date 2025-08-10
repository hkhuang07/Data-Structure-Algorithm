#include <iostream>
#include <vector>
#include <queue>
#include <limits> // For numeric_limits

const int INF = std::numeric_limits<int>::max();

// Structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
};

// Custom comparator for the priority queue
// We want to prioritize nodes with the smallest distance
struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second; // Min-heap behavior
    }
};

// Dijkstra's algorithm to find the shortest path from a source node
void dijkstra(const std::vector<std::vector<Edge>>& graph, int startNode) {
    int numNodes = graph.size();
    std::vector<int> distances(numNodes, INF);
    
    // Priority queue stores pairs of {node, distance}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareDistance> pq;

    distances[startNode] = 0;
    pq.push({startNode, 0});

    while (!pq.empty()) {
        int currentNode = pq.top().first;
        int currentDistance = pq.top().second;
        pq.pop();

        // If the current distance is greater than the stored distance, skip
        if (currentDistance > distances[currentNode]) {
            continue;
        }

        // Iterate through all neighbors of the current node
        for (const auto& edge : graph[currentNode]) {
            int neighbor = edge.to;
            int weight = edge.weight;

            // If a shorter path to the neighbor is found
            if (currentDistance + weight < distances[neighbor]) {
                distances[neighbor] = currentDistance + weight;
                pq.push({neighbor, distances[neighbor]});
            }
        }
    }

    // Print the results
    std::cout << "Shortest distances from node " << startNode << ":" << std::endl;
    for (int i = 0; i < numNodes; ++i) {
        if (distances[i] == INF) {
            std::cout << "Node " << i << ": No path exists" << std::endl;
        } else {
            std::cout << "Node " << i << ": " << distances[i] << std::endl;
        }
    }
}

// Main function to build the graph and run the algorithm
int main() {
    int numNodes = 6;
    std::vector<std::vector<Edge>> graph(numNodes);

    // Build the graph (node, weight)
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 2});
    graph[1].push_back({2, 5});
    graph[1].push_back({3, 10});
    graph[2].push_back({4, 3});
    graph[3].push_back({5, 11});
    graph[4].push_back({3, 4});
    graph[4].push_back({5, 5});

    int startNode = 0;
    dijkstra(graph, startNode);

    return 0;
}