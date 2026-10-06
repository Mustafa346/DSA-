#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
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
void deleteEvenPositions(Node*& head) {
    if (head == NULL)
        return;

    Node* prev = head;
    Node* curr = head->next;
    int position = 2;

    while (curr != NULL) {
        prev->next = curr->next;
        delete curr;
        prev = prev->next;
        if (prev == NULL)
            break;

        curr = prev->next;
        position += 2;
    }
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
    insert(head, 60);

    cout << "Original linked list: ";
    display(head);

    deleteEvenPositions(head);

    cout << "After deleting even-positioned nodes: ";
    display(head);

    return 0;
}
