#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    vector<int> sym((n * (n + 1)) / 2);
    cout << "Enter symmetric matrix elements (lower triangle): ";
    for (int i = 0; i < (n * (n + 1)) / 2; i++) cin >> sym[i];

    vector<vector<int>> mat(n, vector<int>(n, 0));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            mat[i][j] = sym[idx++];
            mat[j][i] = mat[i][j];
        }
    }

    cout << "Symmetric Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
