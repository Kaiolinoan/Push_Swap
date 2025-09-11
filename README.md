# 🧠 push_swap

> Sorting numbers using only two stacks and a limited set of operations — a project for the 42 Lisboa curriculum.

## 📌 Project Overview

`push_swap` is a sorting algorithm challenge that requires sorting a stack of integers with the least number of moves possible. You're restricted to a set of predefined operations and only two stacks: **A** and **B**.

The goal is to implement efficient sorting logic — using a minimal number of instructions — while handling input parsing, memory management, and algorithmic optimization.

---

## ⚙️ How It Works

Your program follows this high-level logic:

1. **Input Validation**  
   Parses and validates arguments, checking for:
   - Empty strings or invalid characters
   - Integers outside the 32-bit signed range
   - Duplicates

2. **Parsing & Conversion**  
   All inputs are split and converted into a **linked list**, where each node represents a number in Stack A.

3. **Normalization**  
   All values are **normalized** to simplify sorting.  
   - Each number is replaced with its index in the sorted array.
   - For example: `[40, 100, 20] → [1, 2, 0]`.

4. **Sorting Algorithm**  
   - If the stack has **5 or fewer** numbers → `small_sort` is used (optimized logic for 2 to 5 numbers).
   - If the stack has **more than 5** numbers → a **Radix Sort** algorithm is applied on the normalized indexes.

5. **Memory Cleanup**  
   After sorting, all allocated memory is freed to ensure there are **no leaks**.

---

## 🔧 Allowed Operations

| Operation | Description |
|----------:|-------------|
| `sa` | swap a – swap the first two elements of stack A |
| `sb` | swap b – swap the first two elements of stack B |
| `ss` | swap both – swap the first two elements of both A and B |
| `pa` | push a – move the top of B to the top of A |
| `pb` | push b – move the top of A to the top of B |
| `ra` | rotate a – shift all elements of A up by 1 |
| `rb` | rotate b – shift all elements of B up by 1 |
| `rr` | rotate both – rotate A and B at the same time |
| `rra` | reverse rotate a – shift all elements of A down by 1 |
| `rrb` | reverse rotate b – shift all elements of B down by 1 |
| `rrr` | reverse rotate both – reverse rotate A and B at the same time |

---

## 🛠️ Compilation

To compile the program, run:
```
make
```

This will create the push_swap executable.

## 🚀 Usage

You can run the program like this:
```
./push_swap 3 2 1
```

Example output:
```
pb
sa
pa
```

Each line is an operation needed to sort the stack.
