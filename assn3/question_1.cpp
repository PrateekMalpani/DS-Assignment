#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        stack[++top] = x;
        cout << x << " pushed into stack." << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop." << endl;
    } else {
        cout << stack[top--] << " popped from stack." << endl;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements are:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << endl << "--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;
        case 5:
            if (isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;  
        default:
            cout << "Invalid choice! Try again." << endl;
        }

        if (choice == 7) break;  
    }

    return 0;
}
