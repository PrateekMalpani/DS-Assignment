#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    vector<int> diag(n);
    cout << "Enter diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (i == j ? diag[i] : 0) << " ";
        }
        cout << endl;
    }
    return 0;
}
