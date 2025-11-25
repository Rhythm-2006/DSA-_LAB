#include <bits/stdc++.h>
using namespace std;

struct QueueArray {
    int front, rear, capacity;
    vector<int> arr;
    QueueArray(int cap) {
        capacity = cap;
        arr.assign(cap, 0);
        front = 0;
        rear = -1;
    }
    bool isEmpty() { return front > rear; }
    bool isFull() { return rear == capacity - 1; }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return INT_MIN;
        }
        return arr[front++];
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return arr[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    int cap;
    cout << "Enter queue capacity: ";
    if (!(cin >> cap)) return 0;
    QueueArray q(cap);
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\n";
        int ch;
        cout << "Enter choice: ";
        cin >> ch;
        if (ch == 7) break;
        if (ch == 1) {
            int x;
            cout << "Enter value: ";
            cin >> x;
            q.enqueue(x);
        } else if (ch == 2) {
            int v = q.dequeue();
            if (v != INT_MIN) cout << "Dequeued: " << v << "\n";
        } else if (ch == 3) {
            cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
        } else if (ch == 4) {
            cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
        } else if (ch == 5) {
            q.display();
        } else if (ch == 6) {
            int v = q.peek();
            if (v != INT_MIN) cout << "Front element: " << v << "\n";
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
