#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Enter string:\n";
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    stack<char> st;
    for (char c : s) st.push(c);
    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    cout << "Reversed: " << res << "\n";
    return 0;
}
