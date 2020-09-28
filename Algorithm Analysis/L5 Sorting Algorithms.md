# Sorting (Design and Analysis)

- [Sorting (Design and Analysis)](#sorting-design-and-analysis)
  - [Definition](#definition)
  - [Selection Sort (Correctness Proof)](#selection-sort-correctness-proof)
    - [Induction on Selection Sort](#induction-on-selection-sort)
  - [Merge Sort](#merge-sort)
    - [Merge Function `merge(L1, L2)`](#merge-function-mergel1-l2)
    - [Recursive Sort Function `mergesort(L)`](#recursive-sort-function-mergesortl)
    - [Merge Sort Algorithm](#merge-sort-algorithm)
  - [Quicksort](#quicksort)
    - [Overview of Quicksort](#overview-of-quicksort)
    - [Partitioning Algorithms for Quicksort](#partitioning-algorithms-for-quicksort)

## Definition

Learn the way to prove:

1. Correctness (Completeness)
2. Time Complexity

## Selection Sort (Correctness Proof)

Given an array S of size n, while S is not empty

1. Pop the smallest element
2. Output it

> If there are remaining elements in S, then the **last element** in the **output sequence** **is no more** than than **all remaining elements**

### Induction on Selection Sort

- [ ] Lecture Slide 19 and 20 (Highlighted)

## Merge Sort

- A Divide and Conquer algorithm

We analyse the sort in a few parts

### Merge Function `merge(L1, L2)`

- Accepts 2 lists and merge them into 1 sorted list, $L$
- merging needs $O(|L1| + |L2|)$ , **linear time**

### Recursive Sort Function `mergesort(L)`

- Given an unsorted list, $L$
- **Base Case :** if $|L| = 0$ or $1$, return $L$
- Base Case is true because
  - size of 0 (nothing to sort)
  - size of 1 (already sorted)

### Merge Sort Algorithm

1. Divide the list into 2 halves, $L1$ and $L2$
2. Call `mergesort(L1)`
3. Call `mergesort(L2)`
4. Call `merge(L1, L2)` (rebuild the list)
5. return the rebuilt list, $L$

> **Note :** most problems lie at the `merge(L1, L2)` function

## Quicksort

- Recursive
- In-place sorting, no temp array needed
- Meant for arrays and is **faster** than mergesort

### Overview of Quicksort

1. Divide the array into 2 sub-arrays (partition) ==burden of this algorithm==
2. Recursively sort 2 sub-arrays
3. Combine the sub-arrays (not a problem because in-place)

### Partitioning Algorithms for Quicksort

1. **Hoare's Algorithm $\theta(n)$:** partitions around the ==first== element of sub-array
2. **Lomuto's Algorithm :** partitions around the ==last== element of sub-array

Refer to notes for Hoare's Algo. step by step