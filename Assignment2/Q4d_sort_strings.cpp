#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    if (!(cin >> n)) return 0;
    vector<string> v(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << "Strings in alphabetical order:\n";
    for (auto &s : v) cout << s << "\n";
    return 0;
}
