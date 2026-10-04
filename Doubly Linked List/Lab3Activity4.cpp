#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct List{
    Node* first;
    Node* last;
};

int main(){
    List* L = new List;
    L->first = NULL;
    L->last = NULL;

    Node* a = new Node{10, NULL, NULL};
    Node* b = new Node{20, NULL, NULL};
    Node* c = new Node{30, NULL, NULL};

    L->first = a;
    L->last = c;
    a->next = b; a->prev = NULL;
    b->next = c; b->prev = a;
    c->next = NULL; c->prev = b;

    Node* p;
    p = L->last;
    L->first = L->first->next;
    free(p);
    if (L->first == NULL){
        L->last == NULL;
    }else{
        L->first->prev = NULL;
    }

    p = L->last;
    L->last = L->last->prev;
    if(L->last == NULL){
        L->first = NULL;
    }else{
        L->last->next = NULL;
        free(p);
    }
    p = b;
    if(L->first == p && L->last == p){
        L->first = NULL;
        L->last = NULL;
        free(p);
    }else if(p == L->first){
        L->first = L->first->next;
        L->first->prev = NULL;
        free(p);
    }else{
        p->next->prev = p->prev;
        p->prev->next = p->next;
        free(p);
    }
    cout << endl;
    return 0;
}