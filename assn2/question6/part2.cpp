#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, nonZero;
    Element data[100];
};

void readMatrix(SparseMatrix &m) {
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> m.rows >> m.cols >> m.nonZero;

    cout << "Enter row col value for each non-zero element:" << endl;
    for (int i = 0; i < m.nonZero; i++) {
        cin >> m.data[i].row >> m.data[i].col >> m.data[i].val;
    }
}

void displayMatrix(SparseMatrix m) {
    cout << "Row\tCol\tValue" << endl;
    for (int i = 0; i < m.nonZero; i++) {
        cout << m.data[i].row << "\t" << m.data[i].col << "\t" << m.data[i].val << endl;
    }
}

SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    SparseMatrix sum;
    sum.rows = a.rows;
    sum.cols = a.cols;
    sum.nonZero = 0;

    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Addition not possible!" << endl;
        sum.nonZero = 0;
        return sum;
    }

    int i = 0, j = 0;
    while (i < a.nonZero && j < b.nonZero) {
        if (a.data[i].row == b.data[j].row && a.data[i].col == b.data[j].col) {
            sum.data[sum.nonZero].row = a.data[i].row;
            sum.data[sum.nonZero].col = a.data[i].col;
            sum.data[sum.nonZero].val = a.data[i].val + b.data[j].val;
            i++; j++; sum.nonZero++;
        } else if (a.data[i].row < b.data[j].row || 
                  (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[sum.nonZero++] = a.data[i++];
        } else {
            sum.data[sum.nonZero++] = b.data[j++];
        }
    }

    while (i < a.nonZero) sum.data[sum.nonZero++] = a.data[i++];
    while (j < b.nonZero) sum.data[sum.nonZero++] = b.data[j++];

    return sum;
}

int main() {
    SparseMatrix A, B, C;

    cout << "Enter first matrix:" << endl;
    readMatrix(A);
    cout << endl << "Matrix A:" << endl;
    displayMatrix(A);

    cout << endl << "Enter second matrix:" << endl;
    readMatrix(B);
    cout << endl << "Matrix B:" << endl;
    displayMatrix(B);

    cout << endl << "A + B:" << endl;
    C = add(A, B);
    displayMatrix(C);

    return 0;
}
