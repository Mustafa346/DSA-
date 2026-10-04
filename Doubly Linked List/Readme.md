# Lab 03 — Doubly Linked List

## Objective

The objective of this lab is to understand and implement the operations performed on a doubly linked list. A doubly linked list allows traversal in both forward and backward directions because each node contains pointers to both the next and previous nodes.

## Topics Covered

* Creation of a doubly linked list
* Insertion of nodes
* Deletion of nodes
* Forward traversal
* Backward traversal
* Complete deletion of a doubly linked list
* Reversing a doubly linked list
* Swapping nodes without swapping their data
* Converting a singly linked list into a doubly linked list

## Lab Activities

### Activity 1 — Creation of Doubly Linked List

Implemented the creation of a doubly linked list using dynamically allocated nodes. Each node contains:

* Data
* Pointer to the next node
* Pointer to the previous node

The list maintains both `first` and `last` pointers.

### Activity 2 — Accessing Nodes

Implemented traversal of the doubly linked list in both directions:

* Forward traversal using the `next` pointer
* Backward traversal using the `prev` pointer

### Activity 3 — Insertion

Implemented insertion of nodes at different positions:

* Before the first node
* After the last node
* After a specified node

### Activity 4 — Deletion

Implemented deletion of nodes from different positions:

* First node
* Last node
* A node specified by its key

### Activity 5 — Complete Deletion

Implemented complete deletion of the doubly linked list by removing all nodes one by one and releasing their dynamically allocated memory.

## Graded Lab Tasks

### Task 1 — Reverse the Doubly Linked List

Implemented a function to reverse the order of nodes in a doubly linked list. The `next` and `prev` links are adjusted so that the list can be traversed correctly in the reversed order.

### Task 2 — Swap Two Nodes

Implemented a function that takes two values from the user, searches for the corresponding nodes, and swaps the positions of the two nodes.

The node data is not swapped. Instead, the links between the nodes are modified.

### Task 3 — Convert Singly Linked List to Doubly Linked List

Implemented a function that takes a singly linked list and creates a doubly linked list containing the same data.

The resulting doubly linked list contains both `next` and `prev` connections, allowing traversal in both directions.

## Concepts Practiced

* Structures and nodes
* Dynamic memory allocation
* Pointers
* `next` and `prev` pointers
* Head/first and tail/last pointers
* Linked list traversal
* Node insertion and deletion
* Pointer manipulation
* List reversal
* Node swapping
* Conversion between linked list types

## Language

**C++**

## Reference

*A Common-Sense Guide to Data Structures and Algorithms*
Jay Wengrow
Pragmatic Bookshelf, 2020

## Conclusion

This lab provided practical implementation of doubly linked lists and their major operations. The graded tasks further extended the implementation by reversing the list, swapping nodes through pointer manipulation, and converting a singly linked list into a doubly linked list.
