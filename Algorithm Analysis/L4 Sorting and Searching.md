# Simple Algorithms

- [Simple Algorithms](#simple-algorithms)
  - [Ground Rules](#ground-rules)
  - [Selection Sort](#selection-sort)
  - [Bubble Sort](#bubble-sort)
  - [Sequential Search](#sequential-search)

## Ground Rules

- An algorithm must be correct (complete)

## Selection Sort

1. Scan the array to find **smallest element** and **swap with first element**.
2. Then, starting with the $i^{th}$ element, scan the elements to the right of it to find the smallest among them and swap it with the $i^{th}$ element.

```cpp
// let arr be an array of sortable elements

for (int i = 0; i <= n - 2; i++){
    int min = i;
    for(int j = i + 1; i <= n - 1; i++){
        if (arr[j] < arr[min])
            min = j; // update the min
    }
    swap(arr[i], arr[min]);
}
```
Time needed

$\theta(n^2)$ 

## Bubble Sort

## Sequential Search

- Optimal for searching an arbitrarily ordered set
