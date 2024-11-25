#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int biCo(int n, int r, vector<vector<int>>& dp) {
    if (dp[n][r] != -1)
        return dp[n][r];

    if (r == 0 || r == n) {
        dp[n][r] = 1;
        return dp[n][r];
    }

    dp[n][r] = biCo(n - 1, r - 1, dp) + biCo(n - 1, r, dp);
    return dp[n][r];
}

int main() {
    int n, r;

    cout << "Enter n and r (n >= r): ";
    cin >> n >> r;

    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    cout << "C(" << n << ", " << r << ") = " << biCo(n, r, dp) << endl;

    return 0;
}

