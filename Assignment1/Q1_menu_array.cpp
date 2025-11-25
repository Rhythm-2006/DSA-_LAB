#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAXN = 100;
    int arr[MAXN];
    int n = 0;
    bool created = false;
    while (true) {
        cout << "\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Linear Search\n6. Exit\n";
        int choice;
        cout << "Enter choice: ";
        if (!(cin >> choice)) return 0;
        if (choice == 6) break;
        if (choice == 1) {
            cout << "Enter number of elements (<= " << MAXN << "): ";
            cin >> n;
            if (n < 0 || n > MAXN) {
                cout << "Invalid size\n";
                n = 0;
                created = false;
                continue;
            }
            cout << "Enter " << n << " elements:\n";
            for (int i = 0; i < n; i++) cin >> arr[i];
            created = true;
        } else if (!created) {
            cout << "Array not created yet\n";
            continue;
        } else if (choice == 2) {
            if (n == 0) cout << "Array is empty\n";
            else {
                cout << "Array elements: ";
                for (int i = 0; i < n; i++) cout << arr[i] << " ";
                cout << "\n";
            }
        } else if (choice == 3) {
            if (n == MAXN) {
                cout << "Array is full\n";
                continue;
            }
            int pos, val;
            cout << "Enter position to insert (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            if (pos < 0 || pos > n) {
                cout << "Invalid position\n";
                continue;
            }
            for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
            arr[pos] = val;
            n++;
        } else if (choice == 4) {
            if (n == 0) {
                cout << "Array is empty\n";
                continue;
            }
            int pos;
            cout << "Enter position to delete (0 to " << n - 1 << "): ";
            cin >> pos;
            if (pos < 0 || pos >= n) {
                cout << "Invalid position\n";
                continue;
            }
            for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
        } else if (choice == 5) {
            int key;
            cout << "Enter element to search: ";
            cin >> key;
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) cout << "Element not found\n";
            else cout << "Element found at index " << idx << "\n";
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
