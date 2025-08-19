#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    vector<int> upper((n * (n + 1)) / 2);
    cout << "Enter upper triangular elements: ";
    for (int i = 0; i < (n * (n + 1)) / 2; i++) cin >> upper[i];

    cout << "Upper Triangular Matrix:" << endl;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) cout << upper[idx++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
