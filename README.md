# 🔗 Doubly Linked List (DLL) in C

A **menu-driven C program** that implements a **Doubly Linked List (DLL)** with all major operations such as creation, insertion, deletion, counting, and traversal (display).  
This project demonstrates one of the most important data structures in C using **dynamic memory allocation** and **bidirectional pointers**.

---

## 🧠 What is a Doubly Linked List?

A **Doubly Linked List (DLL)** is a linear data structure where each node contains three fields:
- A pointer to the **previous node**
- The **data value**
- A pointer to the **next node**

Unlike a singly linked list, a DLL allows **bidirectional traversal** (both forward and backward).

---

## ⚙️ Features

✅ Create a Doubly Linked List (DLL)  
✅ Display all elements in the list  
✅ Insert nodes:
- At the beginning
- At the end
- At a specific position  

✅ Delete nodes:
- From the beginning
- From the end
- From a specific position  

✅ Count total number of nodes  
✅ Menu-driven for easy testing and interaction  

---

## 🧩 Functions Overview

| Function | Description |
|-----------|-------------|
| `createSLL()` | Creates a doubly linked list |
| `displaySLL()` | Displays all nodes in the list |
| `insertFirst()` | Inserts a node at the beginning |
| `insertLast()` | Inserts a node at the end |
| `insertBetween()` | Inserts a node at a given position |
| `deleteFirst()` | Deletes the first node |
| `deleteLast()` | Deletes the last node |
| `deleteBetween()` | Deletes a node from a given position |
| `countNodes()` | Counts the total number of nodes |
| `CN()` | Allocates memory for a new node |

---

## 🧰 Data Structure Used

```c
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;
