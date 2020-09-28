# Time Complexity Analysis (Searching)

- [Time Complexity Analysis (Searching)](#time-complexity-analysis-searching)
  - [Average Case of Sequential Search](#average-case-of-sequential-search)
  - [Searching Revisit](#searching-revisit)
    - [General Facts](#general-facts)
    - [Sorted Arrays](#sorted-arrays)
    - [Linked List (Sorted/Unsorted)](#linked-list-sortedunsorted)
    - [Unsorted Array (Arbitrarily Ordered)](#unsorted-array-arbitrarily-ordered)
  - [Average Case Analysis for Upper Bounds (Worst Case)](#average-case-analysis-for-upper-bounds-worst-case)
  - [Average Case for Binary Search](#average-case-for-binary-search)

## Average Case of Sequential Search

- Average Case : **Probability**

If the target is in the $k^{th}$ position, we need $k$ steps/comparisons

Since each position has the same probability of containing the target, then

$P(target) = \frac{1}{n}$

**Expected Time = probability x step =** $\frac{1}{n}(1) + \frac{1}{n}(2) + ... + \frac{1}{n}(n)$

**Factoring out** $\frac{1}{n}$, we get $\frac{1}{n}(1 + 2 + 3 + ... + n)$

**Which gives** $O(n)$

## Searching Revisit

### General Facts

- Searching a sorted/unsorted list
  - **Worst Case (traverse whole list):** $O(n)$
- Sorted array
  - **Average/Worst Case (bin. search used):** $O(\log{n})$
- For unsorted array
  - **Always** $O(n)$

**Optimal Time** for searching in a linear structure is $O(\log{n})$

### Sorted Arrays

$O(\log{n})$ is the **optimal worst case**

- Comparison based algorithms is **yes**
- It is the lower bound of worst case
- Most optimum and can't do better

### Linked List (Sorted/Unsorted)

- $O(n)$ is the ==optimal worst case== (lower bound of worst case)
- **Note:** lower bound of worst $\neq$ best

### Unsorted Array (Arbitrarily Ordered)

- $O(n)$ is the ==optimal worst case== (lower bound of worst case)
- Prove using **fooling algorithm**

## Average Case Analysis for Upper Bounds (Worst Case)

- Since average case, use **probability**

| Structure      | Time                       |
| -------------- | -------------------------- |
| Linked List    | $O(n)$                     |
| Sorted Array   | $O(\log{n})$ - bin. search |
| Unsorted Array | $O(n)$                     |

Notice that all of them are **same as the worst case**

## Average Case for Binary Search

- [ ] Calculation (Steps)

**If asymp. not used** we can say,

Average Case Time Complexity $\lt$ Worst Case Time Complexity

$\therefore$ Average Case Time Complexity $=\theta(\log{n})$
