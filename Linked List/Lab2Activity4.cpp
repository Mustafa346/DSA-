#include <iostream>
using namespace std;

struct Nodetype{
    int data;
    Nodetype* next;
};
Nodetype* first = NULL;

void insert_end(int value){
    Nodetype* p = new Nodetype;
    p->data = value;
    p->next = NULL;

    if(first == NULL){
        first = p;
    }else{
        Nodetype* temp = first;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void display(){
    Nodetype* temp = first;
    cout << "Linked list: ";
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Nodetype* search(int key){
    Nodetype* p = first;
    while(p != NULL && p->data !=key){
        p = p->next;
    }
    return p;
}

void insert_after(int key , int newval){
    Nodetype* p = search(key);
    if(p == NULL){
        cout << "Value" << key << "Not found!"<<endl;
    }else{
        Nodetype* Newnode = new Nodetype;
        Newnode->data = newval;

        if(p->next == NULL){
            p->next = Newnode;
            Newnode->next = NULL;
        }else{
            Newnode->next = p->next;
            p->next = Newnode;
        }
        cout << "New node " << newval << " inserted after " << key << "." << endl;
    }
}
int main() {
    int choice, val, key;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at end\n";
        cout << "2. Display list\n";
        cout << "3. Search value\n";
        cout << "4. Insert after specific value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert at end: ";
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
            cout << "Enter value after which to insert: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> val;
            insert_after(key, val);
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}