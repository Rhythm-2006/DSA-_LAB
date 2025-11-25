#include <bits/stdc++.h>
using namespace std;

struct CircularQueue {
    int front, rear, size, capacity;
    vector<int> arr;
    CircularQueue(int cap) {
        capacity = cap;
        arr.assign(cap, 0);
        front = 0;
        rear = -1;
        size = 0;
    }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
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
        for (int i = 0; i < size; i++) {
            int idx = (front + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int cap;
    cout << "Enter circular queue capacity: ";
    if (!(cin >> cap)) return 0;
    CircularQueue q(cap);
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
