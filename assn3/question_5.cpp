#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;
    for (char c : expr) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int i = 0; i < val2; i++) res *= val1;
                    s.push(res);
                    break;
                }
            }
        }
    }
    return s.top();
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;

    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
