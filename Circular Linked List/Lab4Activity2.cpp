#include <iostream>
using namespace std;

struct NodeT {
    int key;
    NodeT* next;
};
void accessNodes(NodeT* pNode) {
    NodeT* p;
    p = pNode;

    if (p != NULL) {
        do {
            cout << "Node Data: " << p->key << endl;
            p = p->next;
        } while (p != pNode);
    }
}
NodeT* searchKey(NodeT* pNode, int givenKey) {
    NodeT* p;
    p = pNode;

    if (p != NULL) {
        do {
            if (p->key == givenKey) {
                return p;
            }
            p = p->next;
        } while (p != pNode);
    }
    return NULL;
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

    cout << "Accessing all nodes in Circular Linked List:\n";
    accessNodes(first);
    int searchValue = 30;
    cout << "\nSearching for key " << searchValue << "...\n";

    NodeT* found = searchKey(first, searchValue);
    if (found != NULL)
        cout << "Key found: " << found->key << endl;
    else
        cout << "Key not found in the list." << endl;

    return 0;
}
