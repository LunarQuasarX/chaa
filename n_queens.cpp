#include <bits/stdc++.h>
using namespace std;

bool can_place(pair<int, int> queen, vector<pair<int, int>> *curr_queens, set<pair<int, int>> *reserved) {
    for (auto &q : *curr_queens) {
        if (q.first == queen.first || q.second == queen.second)
            return false;
        if (abs(q.first - queen.first) == abs(q.second - queen.second))
            return false;
    }

    if (reserved->find(queen) != reserved->end())
        return false;

    return true;
}

void place_queens(vector<pair<int, int>> curr_queens, int row, int *count, set<pair<int, int>> *reserved) {
    for (int col = 0; col < 8; col++) {
        if (can_place({row, col}, &curr_queens, reserved)) {
            curr_queens.push_back({row, col});

            if (row == 7) {
                (*count)++;
            } else {
                place_queens(curr_queens, row + 1, count, reserved);
            }

            curr_queens.pop_back();
        }
    }
}

int main () {
    set<pair<int, int>> reserved;

    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 8; j++) {
            if (s[j] == '*')
                reserved.insert({i, j});
        }
    }

    int count = 0;

    place_queens({}, 0, &count, &reserved);
    cout << count << endl;
}
