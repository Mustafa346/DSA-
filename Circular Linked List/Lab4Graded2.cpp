#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* createCircularList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    Node* newNode;

    for (int i = 1; i <= n; i++) {
        newNode = new Node;
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head;
    return head;
}
int josephus(int n, int k) {
    Node* head = createCircularList(n);
    Node* prev = NULL;
    Node* temp = head;
    while (temp->next != temp) {
        for (int i = 1; i < k; i++) {
            prev = temp;
            temp = temp->next;
        }
        cout << "Person " << temp->data << " is eliminated." << endl;
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
    }
    int survivor = temp->data;
    delete temp;
    return survivor;
}

int main() {
    int n = 7;
    int k = 3;

    cout << "There are " << n << " people in the circle." << endl;
    cout << "Every " << k << "rd person will be eliminated." << endl << endl;

    int survivor = josephus(n, k);

    cout << "\nThe survivor is person number " << survivor << "." << endl;

    return 0;
}
