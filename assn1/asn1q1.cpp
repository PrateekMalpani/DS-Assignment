#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int n = 0; // current number of elements

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Limit exceeded. Max allowed is " << MAX << "." << endl;
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully." << endl;
}

void display() {
    if (n == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    int pos, value;
    if (n >= MAX) {
        cout << "Array is full, cannot insert." << endl;
        return;
    }
    cout << "Enter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position." << endl;
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    cout << "Element inserted successfully." << endl;
}

void del() {
    int pos;
    if (n == 0) {
        cout << "Array is empty, cannot delete." << endl;
        return;
    }
    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position." << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully." << endl;
}

void linearSearch() {
    int key;
    bool found = false;
    if (n == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << "." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << endl << "MENU" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
