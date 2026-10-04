#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};
DNode* convert(SNode* head) {
    if (!head) return NULL;

    DNode* dhead = new DNode{head->data, NULL, NULL};
    DNode* dtail = dhead;
    head = head->next;

    while (head) {
        DNode* newNode = new DNode{head->data, dtail, NULL};
        dtail->next = newNode;
        dtail = newNode;
        head = head->next;
    }
    return dhead;
}
SNode* insertS(SNode* head, int data) {
    SNode* n = new SNode{data, NULL};
    if (!head) return n;
    SNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    return head;
}
void printD(DNode* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

int main() {
    SNode* shead = NULL;
    shead = insertS(shead, 10);
    shead = insertS(shead, 20);
    shead = insertS(shead, 30);
    shead = insertS(shead, 40);
    DNode* dhead = convert(shead);

    cout << "Doubly Linked List: ";
    printD(dhead);

    return 0;
}
