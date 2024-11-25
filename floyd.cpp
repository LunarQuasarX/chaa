#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, 5},
        {2, 0, INT_MAX, 4},
        {INT_MAX, 1, 0, INT_MAX},
        {INT_MAX, INT_MAX, 2, 0}
    };

    floydWarshall(graph);

    return 0;
}

