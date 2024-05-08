#include <iostream>
#include <vector>
using namespace std;

int matrix[20][20];

void accept(int n, int m, char color[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Is there an edge between " << i << " and " << j << " : ";
            cin >> matrix[i][j];
            matrix[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i <m; i++) {
        cout << "Enter color " << i+1 << " name: ";
        cin >> color[i];
    }
}

void coloring(int n, int m, char color[])
{
    char solution[20] = {0};
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < m; c++) {
            bool isSafe = true;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] && solution[j] == color[c]) {
                    isSafe = false;
                    break;
                }
            }
            if (isSafe) {
                solution[i] = color[c];
                break;
            }
        }
    }
    cout << "Coloring of Graph:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << solution[i] << endl;
    }
}

int main() {
    int total_nodes, total_colors;
    char color[20];
    cout << "Enter total number of nodes in the graph: ";
    cin >> total_nodes;
    cout << "Enter total number of colors: ";
    cin >> total_colors;
    accept(total_nodes, total_colors, color);
    coloring(total_nodes, total_colors, color);

return 0;
}