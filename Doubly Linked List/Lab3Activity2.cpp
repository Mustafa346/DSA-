#include <iostream>
using namespace std;

struct Nodetype{
    int data;
    Nodetype *next;
    Nodetype *prev;
};

struct list{
    Nodetype *first;
    Nodetype *last;
};

int main(){
    list L;
    L.first = NULL;
    L.last = NULL;

    Nodetype *n1 = new Nodetype{10 , NULL , NULL};
    Nodetype *n2 = new Nodetype{20 , NULL , NULL};
    Nodetype *n3 = new Nodetype{30 , NULL , NULL};

    L.first = n1;
    L.last = n3;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    Nodetype *p;

    cout << "Forward traversal: ";
    for( p = L.first ; p != NULL ; p = p->next){
        cout << p->data << " ";
    }
    cout << "Backward traversal: ";
    for( p = L.last ; p != NULL; p->prev){
        cout << p->data << " ";
    }
    return 0;
}