#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void pushOneQ(int x) {
    int size = q.size();
    q.push(x);
    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
}

void popOneQ() {
    if (q.empty()) {
        cout << "Stack is EMPTY!" << endl;
        return;
    }
    q.pop();
}

int topOneQ() {
    if (q.empty()) {
        cout << "Stack is EMPTY!" << endl;
        return -1;
    }
    return q.front();
}

bool isEmptyOneQ() {
    return q.empty();
}

int main() {
    int op, x;
    do {
        cout << endl << "Stack using One Queue" << endl;
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
                pushOneQ(x);
                break;
            case 2:
                popOneQ();
                break;
            case 3:
                cout << "Top: " << topOneQ() << endl;
                break;
            case 4:
                cout << (isEmptyOneQ() ? "Stack is EMPTY" : "Stack is NOT empty") << endl;
                break;
        }
    } while (op != 5);

    return 0;
}
