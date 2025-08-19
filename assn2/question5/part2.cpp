#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    vector<int> tri(3 * n - 2);
    cout << "Enter tri-diagonal elements: ";
    for (int i = 0; i < 3 * n - 2; i++) cin >> tri[i];

    cout << "Tri-diagonal Matrix:" << endl;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) <= 1) cout << tri[idx++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
