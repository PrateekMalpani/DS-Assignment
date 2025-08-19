#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = arr[0];
    int high = arr[n - 1];

    int total_sum = 0;
    for (int i = low; i <= high; i++) {
        total_sum += i;
    }

    int arr_sum = 0;
    for (int i = 0; i < n; i++) {
        arr_sum += arr[i];
    }

    cout << "Missing number: " << total_sum - arr_sum << endl;

    return 0;
}
