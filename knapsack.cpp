#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int knapSackRec(int W, const vector<int>& wt, const vector<int>& val, int i, vector<vector<int>>& dp) {
    if (i < 0)
        return 0;

    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W) {
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    } else {
        dp[i][W] = max(
            val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp),
            knapSackRec(W, wt, val, i - 1, dp)
        );
        return dp[i][W];
    }
}

int main() {
    vector<int> val = {60, 100, 120, 50};
    vector<int> wt = {10, 20, 30, 40};  
    int W = 50;                 

    int n = val.size();            

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << "Maximum profit: " << knapSackRec(W, wt, val, n - 1, dp) << endl;

    return 0;
}

