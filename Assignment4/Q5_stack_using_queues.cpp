#include <bits/stdc++.h>
using namespace std;

struct StackUsingQueues {
    queue<int> q1, q2;
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
    void display() {
        queue<int> temp = q1;
        if (temp.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

int main() {
    StackUsingQueues s;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        int ch;
        cout << "Enter choice: ";
        if (!(cin >> ch)) return 0;
        if (ch == 5) break;
        if (ch == 1) {
            int x;
            cout << "Enter value: ";
            cin >> x;
            s.push(x);
        } else if (ch == 2) {
            int v = s.pop();
            if (v != INT_MIN) cout << "Popped: " << v << "\n";
        } else if (ch == 3) {
            int v = s.top();
            if (v != INT_MIN) cout << "Top element: " << v << "\n";
        } else if (ch == 4) {
            s.display();
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
