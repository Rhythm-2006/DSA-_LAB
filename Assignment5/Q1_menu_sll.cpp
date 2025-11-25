#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

void insertBeginning(Node* &head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertEnd(Node* &head, int val) {
    Node* n = new Node(val);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

Node* findNode(Node* head, int val) {
    while (head) {
        if (head->data == val) return head;
        head = head->next;
    }
    return nullptr;
}

void insertBefore(Node* &head, int key, int val) {
    if (!head) return;
    if (head->data == key) {
        insertBeginning(head, val);
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Key not found\n";
        return;
    }
    Node* n = new Node(val);
    prev->next = n;
    n->next = curr;
}

void insertAfter(Node* head, int key, int val) {
    Node* node = findNode(head, key);
    if (!node) {
        cout << "Key not found\n";
        return;
    }
    Node* n = new Node(val);
    n->next = node->next;
    node->next = n;
}

void deleteBeginning(Node* &head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd(Node* &head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
}

void deleteSpecific(Node* &head, int key) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (head->data == key) {
        deleteBeginning(head);
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Key not found\n";
        return;
    }
    prev->next = curr->next;
    delete curr;
}

int searchNode(Node* head, int key) {
    int pos = 0;
    while (head) {
        if (head->data == key) return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

void display(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    cout << "Linked list: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    while (true) {
        cout << "\n1. Insert at beginning\n2. Insert at end\n3. Insert before value\n4. Insert after value\n5. Delete from beginning\n6. Delete from end\n7. Delete specific node\n8. Search node\n9. Display\n10. Exit\n";
        int ch;
        cout << "Enter choice: ";
        if (!(cin >> ch)) return 0;
        if (ch == 10) break;
        int val, key;
        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBeginning(head, val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertEnd(head, val);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> val;
                insertBefore(head, key, val);
                break;
            case 4:
                cout << "Enter key and value: ";
                cin >> key >> val;
                insertAfter(head, key, val);
                break;
            case 5:
                deleteBeginning(head);
                break;
            case 6:
                deleteEnd(head);
                break;
            case 7:
                cout << "Enter key: ";
                cin >> key;
                deleteSpecific(head, key);
                break;
            case 8:
                cout << "Enter key: ";
                cin >> key;
                val = searchNode(head, key);
                if (val == -1) cout << "Not found\n";
                else cout << "Found at position (0-based) " << val << "\n";
                break;
            case 9:
                display(head);
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
