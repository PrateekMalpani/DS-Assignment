#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements. Cannot interleave." << endl;
        return;
    }

    vector<int> arr;
    while (!q.empty()) {
        arr.push_back(q.front());
        q.pop();
    }

    int i = 0, j = n / 2;
    while (i < n / 2 && j < n) {
        q.push(arr[i]);
        q.push(arr[j]);
        i++;
        j++;
    }
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    cout << "Original Queue: ";
    displayQueue(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    displayQueue(q);

    return 0;
}
