#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* insertEnd(Node* head, int data) {
    Node* n = new Node{data, NULL, NULL};
    if (!head) return n;
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
    return head;
}

void printList(Node* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

Node* search(Node* head, int val) {
    while (head && head->data != val) head = head->next;
    return head;
}

Node* swapNodes(Node* head, int x, int y) {
    if (x == y) return head;
    Node* a = search(head, x), *b = search(head, y);
    if (!a || !b) return head;
    if (a->prev) a->prev->next = b; if (a->next) a->next->prev = b;
    if (b->prev) b->prev->next = a; if (b->next) b->next->prev = a;

    swap(a->prev, b->prev);
    swap(a->next, b->next);

    if (head == a) head = b;
    else if (head == b) head = a;

    return head;
}

int main() {
    Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    cout << "Original: "; printList(head);
    head = swapNodes(head, 20, 40);
    cout << "After Swap: "; printList(head);
}
