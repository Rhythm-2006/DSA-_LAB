#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^';
}

string infixToPostfix(const string &s) {
    stack<char> st;
    string res;
    for (char c : s) {
        if (isalnum(c)) res.push_back(c);
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res.push_back(st.top());
                st.pop();
            }
            if (!st.empty() && st.top() == '(') st.pop();
        } else if (isOperator(c)) {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                res.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        if (st.top() != '(') res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main() {
    string s;
    cout << "Enter infix expression:\n";
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    cout << "Postfix: " << infixToPostfix(s) << "\n";
    return 0;
}
