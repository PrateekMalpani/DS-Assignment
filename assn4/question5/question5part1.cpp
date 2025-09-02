#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void pushTwoQ(int x) {
    q2.push(x);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void popTwoQ() {
    if (q1.empty()) {
        cout << "Stack is EMPTY!" << endl;
        return;
    }
    q1.pop();
}

int topTwoQ() {
    if (q1.empty()) {
        cout << "Stack is EMPTY!" << endl;
        return -1;
    }
    return q1.front();
}

bool isEmptyTwoQ() {
    return q1.empty();
}

int main() {
    int op, x;
    do {
        cout << endl << "Stack using Two Queues" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Is Empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter operation: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                pushTwoQ(x);
                break;
            case 2:
                popTwoQ();
                break;
            case 3:
                cout << "Top: " << topTwoQ() << endl;
                break;
            case 4:
                cout << (isEmptyTwoQ() ? "Stack is EMPTY" : "Stack is NOT empty") << endl;
                break;
        }
    } while (op != 5);

    return 0;
}
