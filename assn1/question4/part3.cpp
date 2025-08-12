#include <iostream>
using namespace std;

int main() {
    int mat[10][10], transpose[10][10];
    int rows, cols;

    cout << "Enter rows and columns of matrix: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];

    // Transpose
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transpose[j][i] = mat[i][j];

    cout << "Transpose of the matrix:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
