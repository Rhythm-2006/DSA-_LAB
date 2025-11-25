#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &a, int key) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    int idx = binarySearch(a, key);
    if (idx == -1) cout << "Not found\n";
    else cout << "Found at index " << idx << "\n";
    return 0;
}
