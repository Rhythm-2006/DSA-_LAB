#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

void insertEnd(Node* &head, int val) {
    Node* n = new Node(val);
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

int deleteOccurrences(Node* &head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    Node* prev = nullptr;
    while (curr) {
        if (curr->data == key) {
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
            count++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return count;
}

void display(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    if (!(cin >> n)) return 0;
    Node* head = nullptr;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertEnd(head, x);
    }
    int key;
    cout << "Enter key: ";
    cin >> key;
    int cnt = deleteOccurrences(head, key);
    cout << "Count: " << cnt << "\n";
    cout << "Updated Linked List: ";
    display(head);
    return 0;
}
