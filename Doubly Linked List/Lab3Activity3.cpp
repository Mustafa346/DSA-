#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
struct List{
    Node *first;
    Node *last;
};
int main(){
    List* L = new List;
    L->first = NULL;
    L->last = NULL;

    Node* p = new Node;
    p->data = 10;
    if( L->first == NULL){
        L->first = L->last = p;
        p->next = p->prev = NULL;
    }else{
        p->next = L->first;
        p->prev = NULL;
        L->first->prev = p;
        L->first = p;
    }
    for(Node* q = L->first; q!= NULL; q = q->next){
        cout << q->data << " ";
    }
    cout << endl;
    for( Node* q = L->last; q !=NULL; q = q->prev){
        cout << q->data << " ";
    }
    cout << endl;
    return 0;
}