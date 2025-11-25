#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even\n";
        return;
    }
    int half = n / 2;
    queue<int> first;
    for (int i = 0; i < half; i++) {
        first.push(q.front());
        q.pop();
    }
    while (!first.empty()) {
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    int n;
    cout << "Enter even number of elements: ";
    if (!(cin >> n)) return 0;
    queue<int> q;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    interleave(q);
    cout << "Interleaved queue:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}
