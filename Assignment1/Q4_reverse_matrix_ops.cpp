#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &a) {
    int i = 0, j = (int)a.size() - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void inputMatrix(vector<vector<int>> &m, int r, int c) {
    m.assign(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> m[i][j];
}

void printMatrix(const vector<vector<int>> &m) {
    for (auto &row : m) {
        for (auto x : row) cout << x << " ";
        cout << "\n";
    }
}

vector<vector<int>> multiplyMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int r1 = A.size(), c1 = A[0].size();
    int r2 = B.size(), c2 = B[0].size();
    vector<vector<int>> C(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++)
        for (int k = 0; k < c1; k++)
            for (int j = 0; j < c2; j++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>> &A) {
    int r = A.size(), c = A[0].size();
    vector<vector<int>> T(c, vector<int>(r));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];
    return T;
}

int main() {
    while (true) {
        cout << "\n1. Reverse elements of 1D array\n2. Matrix multiplication\n3. Transpose of matrix\n4. Exit\n";
        int ch;
        cout << "Enter choice: ";
        if (!(cin >> ch)) return 0;
        if (ch == 4) break;
        if (ch == 1) {
            int n;
            cout << "Enter n: ";
            cin >> n;
            vector<int> a(n);
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) cin >> a[i];
            reverseArray(a);
            cout << "Reversed array:\n";
            for (int x : a) cout << x << " ";
            cout << "\n";
        } else if (ch == 2) {
            int r1, c1, r2, c2;
            cout << "Enter rows and cols of first matrix: ";
            cin >> r1 >> c1;
            cout << "Enter rows and cols of second matrix: ";
            cin >> r2 >> c2;
            if (c1 != r2) {
                cout << "Matrix multiplication not possible\n";
                continue;
            }
            vector<vector<int>> A, B;
            cout << "Enter first matrix:\n";
            inputMatrix(A, r1, c1);
            cout << "Enter second matrix:\n";
            inputMatrix(B, r2, c2);
            auto C = multiplyMatrix(A, B);
            cout << "Product matrix:\n";
            printMatrix(C);
        } else if (ch == 3) {
            int r, c;
            cout << "Enter rows and cols: ";
            cin >> r >> c;
            vector<vector<int>> A;
            cout << "Enter matrix:\n";
            inputMatrix(A, r, c);
            auto T = transposeMatrix(A);
            cout << "Transpose:\n";
            printMatrix(T);
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
