#include <iostream>
using namespace std;

struct Nodetype{
    int data;
    Nodetype* next;
};

Nodetype* first = NULL;
Nodetype* last = NULL;

void insert_end(){
    Nodetype *p;
    p = new Nodetype;

    cout << "Enter the data in nodes: ";
    cin >> p->data;
    p->next = NULL;

    if(first == NULL){
        first = last = p;
    }else{
        last->next = p;
        last = p;
    }
}

void insert_start(){
    Nodetype *p;
    p = new Nodetype;

    cout << "Enter the data in nodes: ";
    cin >> p->data;
    p->next = NULL;

    if(first == NULL){
        first = last = p;
    }else{
        p->next = first;
        first = p;
    }
}

void display(){
    Nodetype* temp = first;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice;

    do {
        cout << "\nMENU\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert_start();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}