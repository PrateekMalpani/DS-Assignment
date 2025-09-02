#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int count[26] = {0};

    for (char ch : str) {
        q.push(ch);
        count[ch - 'a']++;

        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Output: ";
    firstNonRepeating(s);

    return 0;
}
