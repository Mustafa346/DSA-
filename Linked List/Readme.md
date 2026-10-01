# Lab 02 — Singly Linked List

## Overview

This lab focuses on the implementation and manipulation of **Singly Linked Lists in C++**. It covers the fundamental operations required to create, traverse, insert, search, and delete nodes in a dynamically allocated linked list.

The implementation uses pointers and dynamic memory allocation to manage nodes and maintain the links between them.

## Objectives

* Understand the structure and working of a singly linked list.
* Create and manage nodes dynamically using pointers.
* Perform insertion and deletion operations.
* Traverse and access linked-list nodes.
* Search for specific data elements.
* Handle different linked-list conditions, including empty lists and single-node lists.

## Topics Covered

### Linked List Creation

* Node structure
* Dynamic memory allocation
* `first` and `last` pointers
* Linking nodes using the `next` pointer

### Insertion Operations

* Insertion at the beginning
* Insertion at the end
* Insertion after a specific value

### Searching and Traversal

* Traversing all nodes
* Searching for a specific data element
* Accessing nodes through pointers

### Deletion Operations

* Deleting the first node
* Deleting the last node
* Deleting a specific node
* Deleting the complete linked list

## Graded Tasks

The lab also includes additional linked-list functionality:

### 1. Reverse Linked List

Implemented approaches for displaying a linked list in reverse order:

* Using an iterative loop
* Using recursion

### 2. Merge Two Linked Lists

A function is implemented to merge two linked lists passed as parameters and create a third linked list containing their elements.

### 3. Find Multiple Occurrences

A function is implemented to search the linked list and identify multiple occurrences of a specified data element.

## Data Structure

Each node contains:

* An integer data field
* A pointer to the next node

The linked list maintains pointers to the first and last nodes, allowing efficient insertion at both ends.

## Technologies Used

* **Language:** C++
* **Data Structure:** Singly Linked List
* **Memory Management:** Dynamic Memory Allocation
* **Concepts:** Pointers, Structures, Functions, Loops, Recursion

## Learning Outcomes

After completing this lab, the following concepts were practiced:

* Working with dynamically allocated memory
* Manipulating pointers
* Creating and linking nodes
* Performing insertion and deletion operations
* Traversing linked structures
* Searching linked-list data
* Implementing iterative and recursive approaches
* Combining multiple linked lists
* Handling edge cases such as empty and single-node lists

## Repository Structure

```text
Lab-02-Singly-Linked-List/
│
├── singly_linked_list.cpp
└── README.md
```

## Conclusion

This lab provides practical implementation of the core operations of a **Singly Linked List** in C++. The additional graded tasks extend the implementation to include reverse traversal, linked-list merging, and detection of multiple occurrences, strengthening understanding of pointer-based dynamic data structures.
