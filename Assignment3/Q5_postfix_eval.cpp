#include <bits/stdc++.h>
using namespace std;

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return b == 0 ? 0 : a / b;
    if (op == '%') return b == 0 ? 0 : a % b;
    return 0;
}

int evaluatePostfix(const string &s) {
    stack<int> st;
    for (char c : s) {
        if (c == ' ') continue;
        if (isdigit(c)) st.push(c - '0');
        else {
            if (st.size() < 2) return 0;
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int val = applyOp(a, b, c);
            st.push(val);
        }
    }
    return st.empty() ? 0 : st.top();
}

int main() {
    string s;
    cout << "Enter postfix expression (single-digit operands):\n";
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    cout << "Result: " << evaluatePostfix(s) << "\n";
    return 0;
}
