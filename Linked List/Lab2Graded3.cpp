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
}void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void findOccurrences(int value) {
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            count++;
        }
        temp = temp->next;
    }

    if (count > 0) {
        cout << "Value " << value << " found " << count << " times in the list." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(20);
    insert(40);
    insert(20);
    insert(50);

    cout << "List: ";
    display();

    findOccurrences(20);
    findOccurrences(30);
    findOccurrences(100);

    return 0;
}
