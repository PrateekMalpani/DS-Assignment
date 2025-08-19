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

SparseMatrix transpose(SparseMatrix m) {
    SparseMatrix t;
    t.rows = m.cols;
    t.cols = m.rows;
    t.nonZero = m.nonZero;

    for (int i = 0; i < m.nonZero; i++) {
        t.data[i].row = m.data[i].col;
        t.data[i].col = m.data[i].row;
        t.data[i].val = m.data[i].val;
    }
    return t;
}

int main() {
    SparseMatrix A, T;

    cout << "Enter sparse matrix:" << endl;
    readMatrix(A);

    cout << endl << "Original Matrix (Triplet form):" << endl;
    displayMatrix(A);

    T = transpose(A);

    cout << endl << "Transpose Matrix (Triplet form):" << endl;
    displayMatrix(T);

    return 0;
}
