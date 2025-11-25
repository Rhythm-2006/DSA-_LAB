#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of characters: ";
    if (!(cin >> n)) return 0;
    vector<char> input(n);
    cout << "Enter characters separated by space:\n";
    for (int i = 0; i < n; i++) cin >> input[i];
    vector<int> freq(256, 0);
    queue<char> q;
    cout << "First non-repeating at each step:\n";
    for (char c : input) {
        freq[(unsigned char)c]++;
        q.push(c);
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) q.pop();
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << "\n";
    return 0;
}
