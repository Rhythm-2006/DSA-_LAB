#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> result;
    unordered_set<int> seen;
    for (int x : a) {
        if (!seen.count(x)) {
            seen.insert(x);
            result.push_back(x);
        }
    }
    cout << "Array after removing duplicates:\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
    return 0;
}
