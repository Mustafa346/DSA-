# Lab 04 – Circular Linked List

## Overview

This lab focuses on the implementation and manipulation of a **Circular Linked List**. A Circular Linked List is a variation of a singly linked list in which the last node points back to the first node instead of pointing to `NULL`.

The lab extends the concepts learned from singly and doubly linked lists and demonstrates how nodes can be created, accessed, inserted, deleted, and completely removed while maintaining the circular structure.

The implementation uses dynamically allocated nodes and pointers to manage the linked list.

---

## Objective

The main objective of this lab is to understand how a **Circular Singly Linked List** works and how its structure differs from a normal singly linked list.

The lab covers the implementation of:

* Creation of a Circular Linked List
* Accessing and traversing nodes
* Searching for a particular node
* Insertion before a specific node
* Insertion after a specific node
* Deletion of a specific node
* Complete deletion of the list
* Deletion based on node values
* Solving the Josephus Problem
* Deletion of nodes at even positions

---

## Circular Linked List

A Circular Linked List is a linked list where the `next` pointer of the last node points back to the first node.

In a normal singly linked list, the structure looks like:

```text
First → Node → Node → Node → NULL
```

In a Circular Linked List, the structure becomes:

```text
       ┌──────────────────────┐
       ↓                      │
First → Node → Node → Node ───┘
```

Therefore, there is no `NULL` at the end of the list.

A node can be represented using a structure containing:

* A data or key field
* A pointer to the next node

The nodes are dynamically allocated during execution.

---

## Important Pointer Concept

In this implementation, a pointer such as `pNode` is used to identify a node in the circular list.

Since the list is circular, traversal cannot simply continue until `NULL` is encountered.

Instead, traversal continues until the pointer reaches the starting node again.

For example:

```text
pNode
  ↓
[10] → [20] → [30] → [40]
  ↑                    │
  └────────────────────┘
```

After visiting `40`, the next node is `10`, which is the starting node.

---

# Solved Lab Activities

## Activity 1 – Creation of Circular Linked List

The first activity focuses on creating a Circular Linked List using dynamically allocated nodes.

The general process is:

1. Initially, the list is empty.
2. A new node is dynamically allocated.
3. Data is stored in the new node.
4. The new node is connected to the existing list.
5. The last node is connected back to the first node.
6. The pointer identifying the list is updated when necessary.

For an empty list, the first node needs to point back to itself:

```text
[10]
 ↑ ↓
 └─┘
```

When additional nodes are inserted:

```text
[10] → [20] → [30]
 ↑             │
 └─────────────┘
```

This ensures that the list remains circular.

---

## Activity 2 – Accessing and Traversing Nodes

The second activity demonstrates how to access every node in a Circular Linked List.

Since there is no `NULL` at the end of the list, traversal is performed until the pointer reaches the starting node again.

For example, if the list contains:

```text
10 → 20 → 30 → 40
↑              │
└──────────────┘
```

The traversal sequence is:

```text
10
20
30
40
```

After reaching `40`, the pointer moves back to `10`. At this point, traversal stops because the starting node has been reached again.

This prevents the program from continuously traversing the circular list.

### Searching for a Node

The same traversal technique can be used to search for a particular key.

The program checks the data stored in each node and compares it with the required value.

If the value is found, the corresponding node is returned.

If the traversal reaches the starting node again without finding the value, the required node does not exist in the list.

---

# Activity 3 – Insertion in Circular Linked List

This activity demonstrates insertion of a new node into an existing Circular Linked List.

Two insertion operations were covered.

## Insertion Before a Specific Node

The first operation inserts a new node before a node containing a particular key.

For example, consider:

```text
10 → 20 → 30 → 40
↑              │
└──────────────┘
```

If a new node containing `15` has to be inserted before `20`, the resulting list becomes:

```text
10 → 15 → 20 → 30 → 40
↑                     │
└─────────────────────┘
```

To perform this operation:

1. Search for the node containing the required key.
2. Keep track of the previous node.
3. Connect the previous node to the new node.
4. Connect the new node to the target node.

The circular connection must remain intact after insertion.

---

## Insertion After a Specific Node

The second operation inserts a new node after a node containing a particular key.

For example:

```text
10 → 20 → 30 → 40
↑              │
└──────────────┘
```

If `25` is inserted after `20`:

```text
10 → 20 → 25 → 30 → 40
↑                     │
└─────────────────────┘
```

The links are adjusted so that:

```text
newNode → nextNode
targetNode → newNode
```

This allows the new node to become part of the circular chain.

---

# Activity 4 – Deleting a Node from Circular Linked List

This activity demonstrates how to remove a specific node from a Circular Linked List.

The program first searches for the node containing the required key.

During the search, the previous node is also tracked because its `next` pointer must be changed when the target node is removed.

For example:

```text
10 → 20 → 30 → 40
↑              │
└──────────────┘
```

If `30` is deleted:

```text
10 → 20 → 40
↑         │
└─────────┘
```

The previous node, `20`, is connected directly to `40`.

### Special Case – Only One Node

If the list contains only one node:

```text
[10]
 ↑ ↓
 └─┘
```

Deleting that node makes the list empty.

The pointer representing the list is then set to `NULL`.

### Deleting the Starting Node

If the node being deleted is the node represented by `pNode`, the pointer must be adjusted to another valid node so that the circular structure remains correct.

---

# Activity 5 – Complete Deletion of Circular Linked List

The fifth activity demonstrates how to delete every node from the Circular Linked List.

The program traverses the list and dynamically deletes each node.

Because the list is circular, traversal continues until the pointer reaches the original starting node again.

After all nodes have been deleted, the list pointer is set to:

```text
NULL
```

This indicates that the Circular Linked List is now empty.

---

# Graded Lab Tasks

## Graded Task 1 – Delete Nodes with Even/Odd Values

The first graded task requires a function that deletes all nodes whose data values are **even or odd**.

For example, consider:

```text
10 → 15 → 20 → 25 → 30 → 35
↑                           │
└───────────────────────────┘
```

If even-valued nodes are deleted, the resulting list becomes:

```text
15 → 25 → 35
↑         │
└─────────┘
```

If odd-valued nodes are deleted, the resulting list becomes:

```text
10 → 20 → 30
↑         │
└─────────┘
```

The important part of this task is maintaining the circular connection after deleting the required nodes.

Special cases such as deleting the first node, last node, or all nodes must also be handled correctly.

---

## Graded Task 2 – Josephus Problem

The second graded task implements the **Josephus Problem** using a Circular Linked List.

The Josephus Problem consists of a group of people or nodes arranged in a circle. Starting from a particular position, a fixed number of positions are counted and the node reached by the count is removed.

The process continues repeatedly until only one node remains.

For example:

```text
1 → 2 → 3 → 4 → 5
↑             │
└─────────────┘
```

If every second node is removed, nodes are eliminated one by one while the circular structure is maintained.

The Circular Linked List is particularly suitable for this problem because after the last node is reached, traversal automatically continues from the first node.

The task demonstrates how circular structures can be used to efficiently simulate repeated elimination.

---

## Graded Task 3 – Delete Even-Positioned Nodes

The third graded task requires deleting all nodes that occur at **even positions** in the Circular Linked List.

Positions start from `1`.

For example:

```text
Position:  1   2   3   4   5   6
Data:     10  20  30  40  50  60
```

The nodes at positions:

```text
2, 4, 6
```

are deleted.

The resulting list is:

```text
10 → 30 → 50
↑         │
└─────────┘
```

An important requirement of this task is that **the last node must also be deleted if its position is even**.

For example, if the list contains six nodes, node `6` must be deleted because position `6` is even.

The circular connection must remain valid after all required nodes are removed.

---

# Key Concepts Learned

Through this lab, the following concepts were practiced:

### 1. Dynamic Memory Allocation

Nodes are created dynamically during program execution. This allows the list to grow and shrink according to the number of nodes required.

### 2. Node Linking

Each node contains a pointer to the next node. In a Circular Linked List, the final node points back to the starting node.

### 3. Circular Traversal

Traversal is different from a normal singly linked list because there is no `NULL` at the end.

The traversal stops when the starting node is reached again.

### 4. Insertion

New nodes can be inserted before or after an existing node by correctly modifying the `next` pointers.

### 5. Deletion

A node can be removed by connecting its previous node directly to its next node.

### 6. Special Cases

Circular Linked Lists require careful handling of:

* Empty lists
* Lists containing one node
* Deleting the first node
* Deleting the last node
* Deleting all nodes
* Deleting all nodes satisfying a condition

### 7. Circular Data Structures

The lab demonstrates why circular structures are useful for problems where processing needs to continue repeatedly from the beginning after reaching the end.

The **Josephus Problem** is a practical example of this concept.

---

# Complexity

For a Circular Linked List, the complexity of common operations depends on whether the required node is already known or must first be searched.

| Operation                                    | Time Complexity |
| -------------------------------------------- | --------------: |
| Traversal                                    |            O(n) |
| Searching                                    |            O(n) |
| Insertion after known node                   |            O(1) |
| Insertion before a node                      |            O(n) |
| Deletion of known node with previous pointer |            O(1) |
| Deletion by searching for a key              |            O(n) |
| Complete deletion                            |            O(n) |

Here, `n` represents the number of nodes in the Circular Linked List.

---

# Lab Outcome

After completing this lab, the implementation demonstrates a practical understanding of **Circular Linked Lists** and their operations.

The lab covers the complete lifecycle of a circular list, starting from node creation and traversal and extending to insertion, deletion, complete list removal, conditional deletion, and solving the Josephus Problem.

The graded activities further demonstrate how Circular Linked Lists can be used to solve problems involving **value-based deletion, repeated circular elimination, and position-based deletion** while maintaining the circular structure of the list.
