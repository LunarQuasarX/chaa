#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainRec(const vector<int>& dims, int i, int j, vector<vector<int>>& dp) {
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainRec(dims, i, k, dp) +
                   matrixChainRec(dims, k + 1, j, dp) +
                   dims[i - 1] * dims[k] * dims[j];

        minCost = min(minCost, cost);
    }

    dp[i][j] = minCost;

    return dp[i][j];
}

int main() {
    vector<int> dims = {40, 20, 30, 10, 30};

    int n = dims.size(); // Number of matrices is n-1

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "Minimum number of multiplications: " << matrixChainRec(dims, 1, n - 1, dp) << endl;

    return 0;
}

