#include <bits/stdc++.h>
using namespace std;

int findMissingBinary(const vector<int> &a) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == mid + 1) l = mid + 1;
        else r = mid - 1;
    }
    return l + 1;
}

int main() {
    int n;
    cout << "Enter n (range 1..n): ";
    if (!(cin >> n)) return 0;
    vector<int> a(n - 1);
    cout << "Enter " << n - 1 << " sorted distinct numbers from 1 to " << n << ":\n";
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    cout << "Missing number is " << findMissingBinary(a) << "\n";
    return 0;
}
