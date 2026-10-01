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

void delete_last() {
    Nodetype *q, *q1;
    q1 = NULL;
    q = first;

    if (q == NULL) {
        cout << "\nLinked List is empty";
    } else {
        while (q != last) {
            q1 = q;
            q = q->next;
        }
        if (q == first) {
            first = last = NULL;
        } else {
            q1->next = NULL;
            last = q1;
        }
        delete q;
        cout << "\nLast node deleted successfully";
    }
}

int main() {
    
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    display();

    delete_last();
    display();

    delete_last();
    display();

    return 0;
}
