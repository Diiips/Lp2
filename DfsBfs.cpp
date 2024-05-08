#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void recursiveDFS(int current, int graph[10][10], int num_vertices, bool visited[]) 
{
    visited[current] = true; 
    cout << current << " ";
    for (int neighbor = 0; neighbor < num_vertices; ++neighbor) 
    {
        if (graph[current][neighbor] == 1 && visited[neighbor] == 0)
        {
            recursiveDFS(neighbor, graph, num_vertices, visited);
        }
    }
}

void recursiveBFS(int start_node, int graph[10][10], int num_vertices, bool visited[], queue<int>& q)
{
    if (q.empty()) return;
    int current = q.front();
    q.pop();
    cout << current << " "; 
    for (int neighbor = 0; neighbor < num_vertices; ++neighbor) {
        if (graph[current][neighbor] == 1 && visited[neighbor]==0) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
    recursiveBFS(start_node, graph, num_vertices, visited, q);
}

int main() {
    int graph[10][10];
    int num_vertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> num_vertices;
    cout << "Enter the adjacency matrix of the graph (0 for no edge):\n";
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = i + 1; j < num_vertices; ++j) 
        { 
            cout << "Enter weight between node " << i << " and node " << j << ": ";
            cin >> graph[i][j];
            graph[j][i] = graph[i][j]; // Make the graph symmetric
        }
    }
    bool visited[num_vertices] = {false};
    int start_node;
    cout << "Enter the starting node for DFS and BFS: ";
    cin >> start_node;
    cout << "DFS traversal from node " << start_node << ":\n";
    recursiveDFS(start_node, graph, num_vertices, visited);
    cout << endl;
    for (int i = 0; i < num_vertices; ++i) {
        visited[i] = false; // Reset visited array for BFS
    }
    cout << "BFS traversal from node " << start_node << ":\n";
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    recursiveBFS(start_node, graph, num_vertices, visited, q);
    cout << endl;
    return 0;
}
