#include <iostream>
using namespace std;

struct Nodetype {
    int data;
    Nodetype *next;
};

Nodetype *first = NULL;
Nodetype *last = NULL;

void insert_end(int value) {
    Nodetype *p = new Nodetype;
    p->data = value;
    p->next = NULL;

    if (first == NULL) {
        first = last = p;
    } else {
        last->next = p;
        last = p;
    }
}

void display() {
    Nodetype *p = first;
    if (p == NULL) {
        cout << "Linked List is empty\n";
        return;
    }
    cout << "Linked List: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void remove_spec(int key) {
    Nodetype *q, *q1;
    q1 = NULL;
    q = first;

    while (q != NULL && q->data != key) {
        q1 = q;
        q = q->next;
    }

    if (q == NULL) {
        cout << "\nNot found supplied key";
    }
    else if (q == first && q == last) {
        
        delete q;
        first = last = NULL;
        cout << "\nDeleted node " << key;
    }
    else if (q == first) {
        
        first = first->next;
        delete q;
        cout << "\nDeleted node " << key;
    }
    else if (q == last) {

        q1->next = NULL;
        last = q1;
        delete q;
        cout << "\nDeleted node " << key;
    }
    else {
        q1->next = q->next;
        delete q;
        cout << "\nDeleted node " << key;
    }
}

int main() {

    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    insert_end(50);

    display();
    remove_spec(30);
    display();

    remove_spec(10);
    display();

    remove_spec(50);
    display();

    remove_spec(100);
    display();

    return 0;
}
