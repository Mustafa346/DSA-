#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int value) {
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

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayReverseLoop() {
    int arr[100], count = 0;
    Node* temp = head;

    while (temp != NULL) {
        arr[count++] = temp->data;
        temp = temp->next;
    }
    for (int i = count - 1; i >= 0; i--) { 
        cout << arr[i] << " ";
    }
    cout << endl;
}
void displayReverseRecursive(Node* node) {
    if (node == NULL) return;
    displayReverseRecursive(node->next);
    cout << node->data << " ";
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Original List: ";
    display();

    cout << "Reverse (Loop): ";
    displayReverseLoop();

    cout << "Reverse (Recursion): ";
    displayReverseRecursive(head);
    cout << endl;

    return 0;
}
