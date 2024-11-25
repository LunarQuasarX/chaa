#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    vector<int> arr = {29, 10, 14, 37, 13};
    selectionSort(arr);
    for (int x : arr) cout << x << " ";
}

