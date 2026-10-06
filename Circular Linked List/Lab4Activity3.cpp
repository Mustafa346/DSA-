#include <iostream>
using namespace std;

struct NodeT {
    int key;
    NodeT* next;
};
void displayList(NodeT* pNode) {
    if (pNode == NULL) return;

    NodeT* temp = pNode;
    do {
        cout << temp->key << " ";
        temp = temp->next;
    } while (temp != pNode);
    cout << endl;
}
void insertBefore(NodeT*& pNode, int givenKey, int newKey) {
    NodeT *p, *q, *q1;
    q1 = NULL;
    q = pNode;
    p = new NodeT;
    p->key = newKey;
    do {
        q1 = q;
        q = q->next;
        if (q->key == givenKey) break;
    } while (q != pNode);
    if (q->key == givenKey) {
        q1->next = p;
        p->next = q;
        if (q == pNode)
            pNode = p;
    }
}
void insertAfter(NodeT*& pNode, int givenKey, int newKey) {
    NodeT *p, *q;
    q = pNode;
    p = new NodeT;
    p->key = newKey;
    do {
        if (q->key == givenKey) break;
        q = q->next;
    } while (q != pNode);
    if (q->key == givenKey) {
        p->next = q->next;
        q->next = p;
    }
}

int main() {
    NodeT* first = NULL;
    NodeT* last = NULL;
    NodeT* p;

    int values[] = {10, 20, 30, 40};
    int n = 4;

    for (int i = 0; i < n; i++) {
        p = new NodeT;
        p->key = values[i];
        p->next = NULL;

        if (last != NULL)
            last->next = p;
        else
            first = p;

        last = p;
    }
    if (last != NULL)
        last->next = first;

    cout << "Original Circular Linked List: ";
    displayList(first);
    cout << "\nInserting 15 before 20...\n";
    insertBefore(first, 20, 15);
    displayList(first);
    cout << "\nInserting 35 after 30...\n";
    insertAfter(first, 30, 35);
    displayList(first);

    return 0;
}
