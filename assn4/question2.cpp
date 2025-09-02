#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % SIZE == front);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot enqueue " << x << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = x;
    cout << x << " enqueued to queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Cannot dequeue." << endl;
        return;
    }
    cout << queue[front] << " dequeued from queue." << endl;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to peek." << endl;
    } else {
        cout << "Front element is: " << queue[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "Circular Queue Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty()) cout << "Queue is EMPTY." << endl;
            else cout << "Queue is NOT empty." << endl;
            break;
        case 6:
            if (isFull()) cout << "Queue is FULL." << endl;
            else cout << "Queue is NOT full." << endl;
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
