#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    cout << "Enter character: ";
    if (!(cin >> c)) return 0;
    if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    cout << "Lowercase: " << c << "\n";
    return 0;
}
