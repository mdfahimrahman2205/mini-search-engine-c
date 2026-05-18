# 🔍 Mini Search Engine in C

## 📌 Overview
This project is a Mini Search Engine built using C programming. It demonstrates how multiple data structures can be combined to index, search, and rank documents efficiently.

The system processes text files, extracts words, and allows users to search for relevant documents based on word frequency.

---

## ⚙️ Features
- Document indexing using Binary Search Tree (BST)
- Word frequency tracking using Linked List
- Ranked search results using Max Heap
- Multiple query processing using Queue
- Search history with undo functionality using Stack
- Document relationship graph

---

## 🧠 Data Structures Used
- Binary Search Tree (BST)
- Linked List
- Heap (Priority Queue)
- Stack
- Queue
- Graph (Adjacency List)

---

## 🔍 How It Works

1. Load documents from the data folder
2. Tokenize and extract words
3. Insert words into BST
4. Track occurrences using linked lists
5. Search words and rank results using heap
6. Maintain history using stack
7. Process multiple queries using queue
8. Build graph connecting related documents

---

## ▶️ How to Run

### Compile:
```bash
gcc main.c bst.c graph.c heap.c list.c queue.c stack.c -o search
