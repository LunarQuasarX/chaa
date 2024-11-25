#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void primMST(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);
    key[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;

        inMST[u] = true;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " " << graph[parent[i]][i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);
    return 0;
}

