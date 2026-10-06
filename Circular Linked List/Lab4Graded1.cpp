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
void deleteEvenOrOdd(Node*& head, bool deleteEven) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        bool condition = deleteEven ? (temp->data % 2 == 0) : (temp->data % 2 != 0);

        if (condition) {
            if (temp == head) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);

    cout << "Original linked list: ";
    display(head);
    deleteEvenOrOdd(head, true);

    cout << "After deleting even nodes: ";
    display(head);

    return 0;
}
