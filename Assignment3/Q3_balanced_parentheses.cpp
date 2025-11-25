#include <bits/stdc++.h>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(const string &s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty() || !isMatching(st.top(), c)) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter expression:\n";
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    cout << (isBalanced(s) ? "Balanced\n" : "Not Balanced\n");
    return 0;
}
