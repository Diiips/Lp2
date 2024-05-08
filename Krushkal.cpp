#include <iostream>
#include <algorithm>

using namespace std;

class Kruskal
{

public:
    int vertices;
    int array[15][15];
    int *visited;
    int node;

    Kruskal()
    {
        cout << "Enter number of vertices : ";
        cin >> vertices;

        visited = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }
    }

    void createGraph()
    {

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                array[i][j] = -1;
            }
        }

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (i == j)
                {
                    array[i][j] = 0;
                    continue;
                }
                else
                {
                    if (array[i][j] == -1)
                    {
                        cout << "Enter the Edge between " << i << "-" << j << ": ";
                        cin >> array[i][j];
                    }
                    array[j][i] = array[i][j];
                }
            }
        }

        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < vertices; i++)
        {
            cout << "\n";
            for (int j = 0; j < vertices; j++)
            {
                cout << array[i][j] << " ";
            }
        }
    }

    void kruskal()
    {
        int totalWeight = 0;

        cout << "\nEdges of Minimum Spanning Tree using Kruskal's Algorithm:\n";

        // Create a structure to represent an edge
        struct Edge
        {
            int src, dest, weight;
        };

        // Create an array to store all edges
        Edge edges[vertices * vertices];

        // Copy all edges from the adjacency matrix to the edges array
        int edgeCount = 0;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = i + 1; j < vertices; j++)
            {
                if (array[i][j] != 0 && array[i][j] != -1)
                {
                    edges[edgeCount].src = i;
                    edges[edgeCount].dest = j;
                    edges[edgeCount].weight = array[i][j];
                    edgeCount++;
                }
            }
        }

        // // Sort edges based on their weights in ascending order
        // sort(edges, edges + edgeCount, [](Edge a, Edge b)
        //      { return a.weight < b.weight; });

        // Sorting edges based on their weights using a simple loop
        for (int i = 0; i < edgeCount - 1; ++i)
        {
            for (int j = i + 1; j < edgeCount; ++j)
            {
                if (edges[i].weight > edges[j].weight)
                {
                    // Swap edges[i] and edges[j]
                    Edge temp = edges[i];
                    edges[i] = edges[j];
                    edges[j] = temp;
                }
            }
        }

        // Kruskal's algorithm
        for (int i = 0; i < edgeCount; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            // Check if adding the current edge forms a cycle or not
            if (findParent(src) != findParent(dest))
            {
                // Include the edge in the MST
                totalWeight += weight;
                cout << src << " - " << dest << " : " << weight << "\n";
                unionSets(src, dest);
            }
        }

        cout << "\nTotal weight of Minimum Spanning Tree: " << totalWeight << "\n";
    }

private:
    // Helper functions for union-find (disjoint set) data structure
    int findParent(int vertex)
    {
        if (visited[vertex] == 0)
            return vertex;
        return findParent(visited[vertex]);
    }

    void unionSets(int src, int dest)
    {
        int srcParent = findParent(src);
        int destParent = findParent(dest);
        visited[srcParent] = destParent;
    }
};

int main()
{
    Kruskal kruskalObj;

    kruskalObj.createGraph();
    kruskalObj.kruskal();

    return 0;
}
