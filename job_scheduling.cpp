#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void jobScheduling(vector<int>& ids, vector<int>& profits, vector<int>& deadlines, int n) {
    vector<pair<int, int>> jobs;
    for (int i = 0; i < ids.size(); i++) {
        jobs.push_back({profits[i], deadlines[i]});
    }

    sort(jobs.rbegin(), jobs.rend()); // Sort by profit in descending order
    vector<int> result(n, -1);
    vector<bool> slot(n, false);

    for (int i = 0; i < jobs.size(); i++) {
        int deadline = jobs[i].second;
        for (int j = min(n, deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = ids[i];
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (result[i] != -1)
            cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> ids = {1, 2, 3, 4, 5};
    vector<int> profits = {100, 19, 27, 25, 15};
    vector<int> deadlines = {2, 1, 2, 1, 3};
    int n = 3;
    jobScheduling(ids, profits, deadlines, n);
    return 0;
}

