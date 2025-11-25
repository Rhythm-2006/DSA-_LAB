#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and cols: ";
    if (!(cin >> r >> c)) return 0;
    vector<vector<int>> a(r, vector<int>(c));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    cout << "Row sums:\n";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) sum += a[i][j];
        cout << "Row " << i << ": " << sum << "\n";
    }
    cout << "Column sums:\n";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += a[i][j];
        cout << "Column " << j << ": " << sum << "\n";
    }
    return 0;
}
