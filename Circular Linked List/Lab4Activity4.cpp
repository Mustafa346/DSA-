#include <iostream>
using namespace std;

struct NodeT {
    int key;
    NodeT* next;
};
void displayList(NodeT* pNode) {
    if (pNode == NULL) {
        cout << "List is empty.\n";
        return;
    }

    NodeT* temp = pNode;
    do {
        cout << temp->key << " ";
        temp = temp->next;
    } while (temp != pNode);
    cout << endl;
}
void deleteNode(NodeT*& pNode, int givenKey) {
    NodeT *p, *q, *q1;
    q = pNode;

    if (q == NULL) {
        cout << "List is empty, cannot delete.\n";
        return;
    }
    do {
        q1 = q;
        q = q->next;
        if (q->key == givenKey)
            break;
    } while (q != pNode);
    if (q->key == givenKey) {
        if (q == q->next) {
            pNode = NULL;
        } else {
            q1->next = q->next;
            if (q == pNode)
                pNode = q1;
        }
        delete q;
    } else {
        cout << "Key not found.\n";
    }
}

int main() {
    NodeT* first = NULL;
    NodeT* last = NULL;
    NodeT* p;

    int values[] = {10, 20, 30, 40, 50};
    int n = 5;

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
    cout << "\nDeleting node with key 10...\n";
    deleteNode(first, 10);
    displayList(first);

    cout << "\nDeleting node with key 30...\n";
    deleteNode(first, 30);
    displayList(first);

    cout << "\nDeleting node with key 50...\n";
    deleteNode(first, 50);
    displayList(first);

    return 0;
}
