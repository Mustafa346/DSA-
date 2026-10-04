#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct List {
    Node* first;
    Node* last;
};

int main() {
    List* L = new List;
    L->first = NULL;
    L->last = NULL;

    Node* a = new Node{10, NULL, NULL};
    Node* b = new Node{20, NULL, NULL};
    Node* c = new Node{30, NULL, NULL};

    L->first = a;
    L->last = c;
    a->next = b; a->prev = NULL;
    b->next = c; b->prev = a;
    c->next = NULL; c->prev = b;

    cout << "List before deletion: ";
    for (Node* q = L->first; q != NULL; q = q->next) {
        cout << q->data << " ";
    }
    cout << endl;

    Node* p;
    while ( L->first != NULL )
    {
        p = L->first;
        L->first = L->first->next;
        free(p);
    }
    L->last = NULL;

    cout << "List deleted completely." << endl;

    return 0;
}
