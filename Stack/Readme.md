# Stack Data Structure in C++

## Introduction

This repository contains the implementation and practical applications of the Stack data structure using C++. A stack is a fundamental linear data structure that stores elements according to the **Last In, First Out (LIFO)** principle.

The implementations cover both array-based and dynamic stack structures, along with common applications such as string reversal, balanced bracket validation, infix-to-postfix conversion, and postfix expression evaluation.

The lab emphasizes understanding stack operations, managing memory, handling boundary conditions, and applying stacks to solve programming problems.

## Objectives

- Understand the structure and working principle of a stack.
- Implement a stack using an array and a C++ class.
- Implement a dynamic stack using a linked list.
- Perform push, pop, and top-element operations.
- Understand stack overflow and underflow conditions.
- Apply stacks to reverse strings.
- Validate balanced parentheses and brackets.
- Convert infix expressions into postfix notation.
- Evaluate postfix expressions using a dynamic stack.
- Understand dynamic memory allocation and pointer manipulation in C++.

## Technologies and Concepts

- **Language:** C++
- **Data Structures:** Stack, Array, Linked List
- **Object-Oriented Programming:** Classes, private data members, public member functions
- **Memory Management:** Dynamic allocation and deallocation
- **Pointers:** Node links and top-pointer management
- **Algorithms:** String reversal, bracket matching, expression conversion, and expression evaluation

## What Is a Stack?

A stack is a linear data structure in which insertion and deletion take place at the same end, called the **top of the stack**.

A stack follows the LIFO principle, meaning the last element inserted is the first element removed.

For example, inserting `A`, `B`, and `C` produces the following stack:

```text
       TOP
        |
       [C]
       [B]
       [A]
```

The removal order is `C`, `B`, and then `A`.

Stacks are commonly used in expression evaluation, function calls, recursion, undo operations, browser history, and syntax checking.

## Fundamental Stack Operations

| Operation | Description |
|---|---|
| `push()` | Inserts an element at the top of the stack. |
| `pop()` | Removes the top element from the stack. |
| `top()` | Returns the top element without removing it. |
| `isEmpty()` | Determines whether the stack contains any elements. |
| `delete` | Removes stored elements and releases allocated memory when applicable. |

### Push Operation

The push operation inserts a new element at the top of the stack.

For an array-based stack, the top index is incremented before storing the new element. For a linked-list stack, a new node is created and linked before the existing top node.

### Pop Operation

The pop operation removes the element at the top of the stack.

In an array-based stack, the top index is decremented. In a linked-list stack, the top pointer is updated to the next node, and the removed node's memory is released.

### Top of Stack

The top of the stack identifies the most recently inserted element that has not yet been removed.

Accessing the top element does not change the stack's contents.

### Stack Overflow

Stack overflow occurs when an element is pushed onto a full, fixed-capacity array stack.

A dynamically allocated linked-list stack does not have a predefined maximum capacity, although it is still limited by available memory.

### Stack Underflow

Stack underflow occurs when a pop operation is attempted on an empty stack.

A correct implementation should detect this condition and handle it without accessing invalid memory.

## Stack Implementation Using an Array

An array-based stack stores elements in consecutive memory locations. A variable such as `tos` (Top of Stack) tracks the index of the top element.

Initially, `tos` is set to `-1`, indicating that the stack is empty. When an element is pushed, the index is incremented. When an element is popped, the index is decremented.

A C++ class can encapsulate the array and its operations, keeping the internal data private while providing public functions to interact with the stack.

### Characteristics

- Uses an array to store elements.
- Maintains the top position using an index.
- Has a fixed capacity when a fixed-size array is used.
- Provides efficient insertion and removal.
- Requires overflow checking before insertion.

### Example

If the following characters are pushed in order:

```text
B, S, S, E, 3, Z
```

The stack returns the characters in reverse order when they are popped:

```text
Z3ESSB
```

Attempting another pop after removing all six elements causes stack underflow.

## Dynamic Stack Implementation Using a Linked List

A dynamic stack uses a linked list instead of a fixed-size array. Each node stores a data element and a pointer to the next node.

The `head` pointer represents the top of the stack. New nodes are inserted at the beginning of the linked list, and removed nodes are deleted from the same position.

### Node Structure

A typical stack node contains:

- **Data:** The value stored in the node.
- **Link:** A pointer to the next node.

### Characteristics

- Grows and shrinks dynamically.
- Does not require a predefined array capacity.
- Uses pointers to connect nodes.
- Allocates memory when new nodes are created.
- Releases memory when nodes are removed.
- Requires careful handling of empty-stack conditions.

### Example

Pushing the characters of `Hello` onto the stack and popping them produces:

```text
olleH
```

This demonstrates how the LIFO principle naturally reverses the order of the stored characters.

## Applications of a Stack

### 1. String Reversal

A stack reverses a string by storing its characters in their original order and removing them in reverse order.

For example:

```text
Original:  I Love Programming
Reversed:  gnimmargorP evoL I
```

This technique works because the last character inserted is the first character removed.

### 2. Balanced Parentheses and Brackets

A stack can determine whether an expression contains correctly matched opening and closing brackets.

The algorithm supports three bracket types:

- Parentheses: `(` and `)`
- Square brackets: `[` and `]`
- Curly brackets: `{` and `}`

**Working principle:**

1. Read the expression from left to right.
2. Push each opening bracket onto the stack.
3. When a closing bracket appears, check whether the stack is empty.
4. If the stack is empty, the expression is unbalanced.
5. Otherwise, compare the closing bracket with the top opening bracket.
6. If the types do not match, the expression is unbalanced.
7. If they match, remove the opening bracket from the stack.
8. After processing the entire expression, the stack must be empty.

**Examples:**

| Expression | Result |
|---|---|
| `[{}(){()}]` | Balanced |
| `[()]{}{[()()]()}` | Balanced |
| `[(])` | Not Balanced |
| `[{( )}]` | Balanced |
| `{[( )] }` | Not Balanced when the bracket types are incorrectly nested |

Correct bracket matching requires both the same bracket type and the correct nesting order.

### 3. Infix-to-Postfix Conversion

An infix expression places operators between operands, whereas a postfix expression places operators after their operands.

For example:

```text
Infix:   A + B
Postfix: AB+
```

A stack is used to temporarily store operators and parentheses during conversion.

The conversion algorithm considers operator precedence, associativity, and parentheses to determine when operators should be added to the output.

**Common operator precedence:**

| Operators | Precedence |
|---|---|
| `^` | High |
| `*`, `/`, `%` | Medium |
| `+`, `-` | Low |

Exponentiation is commonly right-associative, while the other listed arithmetic operators are generally left-associative.

**Example:**

```text
Infix:   A + B * C
Postfix: ABC*+
```

Multiplication is performed before addition, so `B * C` is placed before the addition operator in the postfix expression.

### 4. Postfix Expression Evaluation

Postfix expressions can be evaluated using a stack without requiring parentheses to specify the order of operations.

**Working principle:**

1. Read the postfix expression from left to right.
2. Push each operand onto the stack.
3. When an operator appears, pop the required operands.
4. Apply the operator to the operands in the correct order.
5. Push the result back onto the stack.
6. Continue until the expression is fully processed.
7. For a valid expression, the final stack contains one result.

For a binary operator, the first value popped is the right operand, and the second value popped is the left operand.

**Example:**

```text
Postfix: 23*4+
```

Evaluation:

```text
2 * 3 = 6
6 + 4 = 10
```

Result:

```text
10
```

Postfix evaluation can also use variables, provided their values are supplied before evaluating the expression.

## Time and Space Complexity

Let `n` represent the number of elements or characters being processed.

| Operation or Application | Time Complexity |
|---|---|
| Push | O(1) |
| Pop | O(1) |
| Access top element | O(1) |
| Check whether the stack is empty | O(1) |
| Reverse a string using a stack | O(n) |
| Check balanced brackets | O(n) |
| Convert infix to postfix | O(n) |
| Evaluate a postfix expression | O(n) |

The basic stack operations take constant time. The expression-processing and string-reversal algorithms generally take linear time because they process the input one element at a time.

**Space complexity:**

- An array-based stack uses O(n) space for a capacity of `n`.
- A dynamic stack uses O(n) space for `n` stored nodes.
- String reversal and bracket validation may require O(n) additional stack space.
- Infix-to-postfix conversion and postfix evaluation may also require O(n) additional space in the worst case.

## Graded Lab Tasks

### Task 1 – Balanced Bracket Validation

Develop a C++ application that checks whether an entered string of brackets is balanced. The solution must verify matching bracket types and correct nesting order.

The stack should handle opening and closing parentheses, square brackets, and curly brackets. Expressions containing mismatched brackets, incorrectly nested brackets, or unmatched brackets must be identified as unbalanced.

### Task 2 – Infix-to-Postfix Conversion

Implement an infix-to-postfix conversion algorithm using a dynamic stack.

The implementation should process operators according to precedence and associativity, handle parentheses correctly, and produce the equivalent postfix expression. Multiple input expressions should be used to test the implementation.

### Task 3 – Postfix Expression Evaluation

Implement a postfix expression evaluator using a dynamic stack.

The program should process operands and operators, perform arithmetic operations, and calculate the final numerical result. Where variables are used, their corresponding values must be supplied to the evaluator.

The implementation should preserve the correct operand order and handle invalid expressions appropriately.

## Important Implementation Considerations

- Initialize the top index or pointer correctly when creating a stack.
- Check whether a fixed-size stack is full before pushing an element.
- Check whether a stack is empty before popping or accessing its top.
- Update the top index or pointer correctly after each operation.
- Release dynamically allocated nodes when they are removed.
- Ensure the stack is empty after all elements have been removed.
- Preserve operator precedence and associativity during expression conversion.
- Maintain the correct operand order during postfix evaluation.
- Validate input expressions before performing operations that depend on their structure.

## Learning Outcomes

After completing this lab, the following concepts should be understood:

- The LIFO principle and its role in stack operations.
- The difference between array-based and linked-list-based stacks.
- The use of classes to encapsulate stack functionality.
- The use of pointers and dynamic memory in linked-list implementations.
- The importance of overflow and underflow checks.
- How a stack can reverse data without a separate reversal algorithm.
- How stacks validate nested structures such as parentheses.
- How stacks support infix-to-postfix conversion and postfix evaluation.
- How to analyze the time and space complexity of stack operations and applications.

## Conclusion

The Stack data structure provides an efficient way to manage data when the most recently inserted element must be accessed first. Implementing stacks using arrays and linked lists develops an understanding of data storage, pointer manipulation, class-based design, and memory management.

Stack applications such as string reversal, bracket validation, infix-to-postfix conversion, and postfix evaluation demonstrate how this fundamental data structure can be applied to practical programming problems. These concepts also provide a foundation for understanding recursion, function-call management, parsing, and other advanced algorithms.

## Reference

Wengrow, Jay. *A Common-Sense Guide to Data Structures and Algorithms*. Pragmatic Bookshelf, 2020. Chapter 9.
