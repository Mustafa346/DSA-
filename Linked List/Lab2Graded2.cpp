#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;
Node* head3 = NULL;

void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* merge(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp;
    while (list1 != NULL) {
        insert(result, list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        insert(result, list2->data);
        list2 = list2->next;
    }
    return result;
}

int main() {
    insert(head1, 10);
    insert(head1, 20);
    insert(head1, 30);

    insert(head2, 40);
    insert(head2, 50);
    insert(head2, 60);

    cout << "First List: ";
    display(head1);

    cout << "Second List: ";
    display(head2);
    head3 = merge(head1, head2);

    cout << "Merged List: ";
    display(head3);

    return 0;
}
