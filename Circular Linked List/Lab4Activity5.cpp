#include <iostream>
#include <cstdlib>
using namespace std;

struct NodeT {
    int key;
    NodeT* next;
};
void display(NodeT* pNode) {
    if (pNode == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    NodeT* temp = pNode;
    do {
        cout << temp->key << " ";
        temp = temp->next;
    } while (temp != pNode);
    cout << endl;
}
void deleteAll(NodeT*& pNode) {
    NodeT* p, *p1;
    p = pNode;
    if (pNode == NULL)
        return;

    do {
        p1 = p;
        p = p->next;
        free(p1);
    } while (p != pNode);

    pNode = NULL;
}

int main() {
    NodeT* pNode = NULL;
    NodeT* last = NULL;
    for (int i = 1; i <= 3; i++) {
        NodeT* newNode = new NodeT;
        newNode->key = i * 10;
        if (pNode == NULL) {
            pNode = newNode;
            pNode->next = pNode;
            last = pNode;
        } else {
            newNode->next = pNode;
            last->next = newNode;
            last = newNode;
        }
    }

    cout << "Circular linked list before deletion: ";
    display(pNode);
    deleteAll(pNode);

    cout << "Circular linked list after deletion: ";
    display(pNode);

    return 0;
}
