#include <iostream>
using namespace std;

// Define node structure (same as 'nodetype')
struct nodetype {
    int data;
    nodetype* next;
};

int main() {
    nodetype* first = NULL;
    nodetype* last = NULL;
    nodetype* p;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        p = new nodetype;
        p->data = value;
        p->next = NULL;
        if (last != NULL)
            last->next = p;
        else
            first = p; 

        last = p;
    }
    if (last != NULL)
        last->next = first;
    cout << "\nCircular Linked List: ";
    nodetype* temp = first;
    if (temp != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != first);
    }

    cout << endl;
    return 0;
}
