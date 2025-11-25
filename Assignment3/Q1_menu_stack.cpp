#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int top;
    int capacity;
    vector<int> arr;
    Stack(int cap) {
        top = -1;
        capacity = cap;
        arr.assign(cap, 0);
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }
    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return INT_MIN;
        }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return arr[top];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    int cap;
    cout << "Enter stack capacity: ";
    if (!(cin >> cap)) return 0;
    Stack s(cap);
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        int ch;
        cout << "Enter choice: ";
        cin >> ch;
        if (ch == 7) break;
        if (ch == 1) {
            int x;
            cout << "Enter value: ";
            cin >> x;
            s.push(x);
        } else if (ch == 2) {
            int val = s.pop();
            if (val != INT_MIN) cout << "Popped: " << val << "\n";
        } else if (ch == 3) {
            cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
        } else if (ch == 4) {
            cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
        } else if (ch == 5) {
            s.display();
        } else if (ch == 6) {
            int val = s.peek();
            if (val != INT_MIN) cout << "Top element: " << val << "\n";
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
