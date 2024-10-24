#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size() / 2;
    queue<int> firstHalf;

    for (int i = 0; i < n; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int n, element;
    cout << "Enter the number of elements (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Please enter an even number of elements." << endl;
        return 1;
    }

    queue<int> q;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        q.push(element);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    printQueue(q);

    return 0;
}
