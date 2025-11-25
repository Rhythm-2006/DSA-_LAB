#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter n (range 1..n): ";
    if (!(cin >> n)) return 0;
    vector<int> a(n - 1);
    cout << "Enter " << n - 1 << " distinct numbers from 1 to " << n << ":\n";
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        sum += a[i];
    }
    long long expected = 1LL * n * (n + 1) / 2;
    cout << "Missing number is " << expected - sum << "\n";
    return 0;
}
