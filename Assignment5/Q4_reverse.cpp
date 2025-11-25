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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "->NULL\n";
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
    cout << "Original list: ";
    display(head);
    head = reverseList(head);
    cout << "Reversed list: ";
    display(head);
    return 0;
}
