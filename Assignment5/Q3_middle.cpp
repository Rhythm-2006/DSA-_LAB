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

int middle(Node* head) {
    if (!head) return -1;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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
    int mid = middle(head);
    if (mid == -1) cout << "List is empty\n";
    else cout << "Middle element: " << mid << "\n";
    return 0;
}
