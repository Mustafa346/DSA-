#include <iostream>
using namespace std;


struct Nodetype {
    int data;
    Nodetype* next;
};


Nodetype* first = NULL;


void insert_end(int value) {
    Nodetype* p = new Nodetype;
    p->data = value;
    p->next = NULL;

    if (first == NULL) {
        first = p;
    } else {
        Nodetype* temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display() {
    Nodetype* temp = first;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Nodetype* search(int key) {
    Nodetype* p = first;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    return p;
}

int main() {
    int choice, val;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Display list\n";
        cout << "3. Search value\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> val;
            insert_end(val);
        }
        else if (choice == 2) {
            display();
        }
        else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> val;
            Nodetype* result = search(val);
            if (result != NULL) {
                cout << "Value " << val << " found in list.\n";
            } else {
                cout << "Value not found!\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
