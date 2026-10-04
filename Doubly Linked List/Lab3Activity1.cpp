#include <iostream>
using namespace std;

struct Nodetype{
    int data;
    Nodetype *next;
    Nodetype *prev;
};

Nodetype *first = NULL;
Nodetype *last = NULL;

void insert_end(){
    Nodetype *p = new Nodetype;
    cout << "Enter the data : ";
    cin >> p->data;
    if(first == NULL){
        first = last = p;
    }else{
        last->next = p;
        p->prev = last;
        last = p;
    }
}

void display_forward(){
    Nodetype *temp = first;
    cout << "List (Forward) : ";
    while (temp !=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int choice;
    do{
        cout << "\n--- Menu ---";
        cout << "1. Insert at end\n";
        cout << "2. Display forward\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                insert_end();
                break;
            case 2:
                display_forward();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid Choice! Try again.\n";
        }
    }while (choice !=3);
    return 0;
}