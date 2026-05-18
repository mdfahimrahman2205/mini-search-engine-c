# 🔍 Mini Search Engine with Ranking (C Project)

## 📌 Overview
This project is a Mini Search Engine built using C that demonstrates how multiple data structures can be integrated to perform efficient document indexing, searching, and ranking.

The system processes text files, indexes words, and retrieves relevant documents based on frequency ranking.

---

## ⚙️ Features
- Document indexing using Binary Search Tree (BST)
- Word frequency tracking using Linked List
- Ranked results using Max Heap (Priority Queue)
- Multiple query processing using Queue
- Search history with undo functionality using Stack
- Document similarity graph

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
1. Documents are loaded and tokenized
2. Words are inserted into BST
3. Each word stores occurrences across documents
4. Heap ranks results based on frequency
5. Queue processes multiple queries
6. Stack stores search history
7. Graph connects related documents

---

## 🧪 Testing & Validation

### ✔ Heap (Ranking)
- Verified highest frequency document appears first

### ✔ Case Insensitivity
- Input normalized to lowercase for accurate matching

### ✔ Stack (LIFO)
- Latest search appears first in history

### ✔ Queue (FIFO)
- Queries processed in correct order

### ✔ Graph
- Documents connected based on shared words

### ✔ Edge Cases
- System handles non-existent words without crashing

---

## ⚠️ Challenges
- Memory management across multiple structures
- Graph construction complexity
- Safe string handling in C

---

## 🚫 Limitations
- BST is unbalanced (can degrade to O(n))
- No phrase search support
- Limited scalability for large datasets

---

## ▶️ How to Run

### Compile:
gcc main.c bst.c graph.c heap.c list.c queue.c stack.c util.c -o search

### Run:
./search

---

## 📂 Project Structure
- main.c  
- bst.c / bst.h  
- heap.c / heap.h  
- list.c / list.h  
- queue.c / queue.h  
- stack.c / stack.h  
- graph.c / graph.h  
- util.c  
- common.h  
- data/  

---

## 👨‍💻 Authors
Mir Samiul Hossain
Md. Fahim Rahman  
Md. Habibul Islam


---

## 💡 Key Takeaway
This project demonstrates how combining appropriate data structures can build efficient systems similar to real-world search engines.
