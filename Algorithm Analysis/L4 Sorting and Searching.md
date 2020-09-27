# Simple Algorithms

- [Simple Algorithms](#simple-algorithms)
  - [Ground Rules](#ground-rules)
  - [Selection Sort](#selection-sort)
    - [Selection Sort Time Analysis](#selection-sort-time-analysis)
  - [Bubble Sort](#bubble-sort)
    - [Bubble Sort Time Analysis](#bubble-sort-time-analysis)
    - [Nature of Bubble Sort](#nature-of-bubble-sort)
  - [Sequential Search](#sequential-search)
    - [Sequential Search Time Analysis](#sequential-search-time-analysis)

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

### Selection Sort Time Analysis

Refer to handwritten notes for time

$\theta(n^2)$

## Bubble Sort

1. Compare adjacent elements of the list and exchange them if **out of order**
2. Doing so will **_bubble_** the largest element to the last spot
3. For each pass, the largest element of that pass will go into the last possible spot
4. Will loop for n - 1 passes

```cpp
for (int i = 0; i <= n - 2; i++) {
  for (int j = 0; j <= n - 2 - i; j++) { // the minus offsets the final position based on the iteration
    if(arr[j + 1] < A[j])
      swap(arr[j + 1], A[j]);
  }
}
```

### Bubble Sort Time Analysis

Refer to Slide 11 for easier way and hand notes

### Nature of Bubble Sort

Some elements move down to the end of array; once moves down, it never moves up!

$\theta(n^2)$

## Sequential Search

Very simple algorithm, optimal for searching an arbitrarily ordered set

```cpp
int sequentialSearch(int arr[], int key) {
  i = 0;

  while (i < n) {
    if (arr[i] == key)
      return i;
    else
      i = i + 1;
  }

  return -1;  // not found
}
```

### Sequential Search Time Analysis

In the worst case which is

- No matching elements
- The matching elements at the last

The algorithm makes the largest no. of comparisons $n$ **(We use # of comparisons)**

$\theta{(n)}$
