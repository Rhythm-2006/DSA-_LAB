#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main() {
    string s;
    cout << "Enter string:\n";
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    string res;
    for (char c : s) if (!isVowel(c)) res.push_back(c);
    cout << "String after deleting vowels:\n" << res << "\n";
    return 0;
}
