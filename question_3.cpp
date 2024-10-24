#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void printFirstNegativeInteger(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        if (i >= k - 1) {
            if (!dq.empty()) {
                result.push_back(arr[dq.front()]);
            } else {
                result.push_back(0);
            }
        }
    }

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the window size (k): ";
    cin >> k;

    cout << "First negative integer for each window of size " << k << ":\n";
    printFirstNegativeInteger(arr, k);

    return 0;
}
