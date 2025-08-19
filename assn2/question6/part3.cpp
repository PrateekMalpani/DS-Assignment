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

SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    SparseMatrix prod;
    prod.rows = a.rows;
    prod.cols = b.cols;
    prod.nonZero = 0;

    if (a.cols != b.rows) {
        cout << "Multiplication not possible!" << endl;
        return prod;
    }

    for (int i = 0; i < a.nonZero; i++) {
        for (int j = 0; j < b.nonZero; j++) {
            if (a.data[i].col == b.data[j].row) {
                int r = a.data[i].row;
                int c = b.data[j].col;
                int v = a.data[i].val * b.data[j].val;

                bool found = false;
                for (int k = 0; k < prod.nonZero; k++) {
                    if (prod.data[k].row == r && prod.data[k].col == c) {
                        prod.data[k].val += v;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    prod.data[prod.nonZero].row = r;
                    prod.data[prod.nonZero].col = c;
                    prod.data[prod.nonZero].val = v;
                    prod.nonZero++;
                }
            }
        }
    }
    return prod;
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

    cout << endl << "A * B:" << endl;
    C = multiply(A, B);
    displayMatrix(C);

    return 0;
}
