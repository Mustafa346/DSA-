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
void delete_first() {
    Nodetype *p;
    if (first == NULL) {
        cout << "\nLinked List is empty";
    } else {
        p = first;
        first = first->next;
        delete(p);
        cout << "\nFirst node deleted successfully";
    }
}

int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    display();

    delete_first(); 
    display();

    delete_first();
    display();

    return 0;
}
