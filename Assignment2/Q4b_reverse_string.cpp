#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Enter string:\n";
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    reverse(s.begin(), s.end());
    cout << "Reversed string:\n" << s << "\n";
    return 0;
}
