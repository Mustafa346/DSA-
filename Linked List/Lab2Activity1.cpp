#include <iostream>
using namespace std;

struct Nodetype
{
    int data;
    Nodetype* next;
};

Nodetype* first = NULL;
Nodetype* last = NULL;

void insert_end(){
    Nodetype *p;
    p = new Nodetype;

    cout << "Enter the value : ";
    cin >> p->data;
    p->next = NULL;

    if(first == NULL){
        first =  last = p;
    }else{
        last->next = p;
        last = p;
    }
}

void display(){
    Nodetype* temp = first;
    while(temp != NULL){
        cout << temp->data<< " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    int n;
    cout<< " How many nodes you want to insert ? ";
    cin >> n;

    for(int i =0; i<n; i++){
        insert_end();
    }
    cout << "Linked list : ";
    display();
    return 0;
}
