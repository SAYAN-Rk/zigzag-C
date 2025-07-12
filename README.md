# 🚀 Zigzag Compressed Path Sum

This project implements the **"Compressed Path Sum in Zigzag Matrix"** challenge as part of the Qualification Round. It involves diagonal matrix traversal and prime-aware summation logic, implemented in pure C using pointers.

---

## 🧩 Problem Statement

You are given a square matrix `N x N` of positive integers. Your task is to:

1. Traverse the matrix in a **zigzag diagonal pattern**, starting from the top-left:
   - Alternate between **↗ up-right** and **↙ down-left** diagonals.
2. Maintain a **running sum** of visited elements.
3. For every **prime number**, **subtract it** from the sum instead of adding.

You must use **pointer arithmetic only** for matrix traversal.

---

## 🧪 Sample Input & Output

### Input:
```c
n = 3

matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```
---

## Zigzag Traversal Order:
```
1 → 2 → 4 → 5 → 3 → 6 → 8 → 7 → 9
```
---
Prime Numbers in Path:
```
2, 3, 5, 7
```
---
Computed Sum:
```
1 + (-2) + 4 + (-5) + (-3) + 6 + 8 + (-7) + 9 = 11
```
---
Output: 11
---
Function Signature
```
int compute_zigzag_sum(int** matrix, int n);
```
