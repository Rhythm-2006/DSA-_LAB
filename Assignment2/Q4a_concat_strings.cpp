#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string:\n";
    getline(cin, s1);
    if (s1.size() == 0) getline(cin, s1);
    cout << "Enter second string:\n";
    getline(cin, s2);
    string res = s1 + s2;
    cout << "Concatenated string:\n" << res << "\n";
    return 0;
}
