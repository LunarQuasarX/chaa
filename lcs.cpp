#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsRec(const string& X, const string& Y, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (X[m - 1] == Y[n - 1]) {
        dp[m][n] = 1 + lcsRec(X, Y, m - 1, n - 1, dp);
    } else {
        dp[m][n] = max(lcsRec(X, Y, m - 1, n, dp), lcsRec(X, Y, m, n - 1, dp));
    }

    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int m = X.size();
    int n = Y.size(); 

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << "Length of Longest Common Subsequence: " << lcsRec(X, Y, m, n, dp) << endl;

    return 0;
}

