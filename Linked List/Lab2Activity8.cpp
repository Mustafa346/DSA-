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

void delete_all() {
    Nodetype *p;
    while (first != NULL) {
        p = first;
        first = first->next;
        delete p;
    }
    last = NULL;
    cout << "\nAll nodes deleted successfully";
}

int main() {
    
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    insert_end(50);

    display();

    
    delete_all();

    display();

    return 0;
}
