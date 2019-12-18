## [Round G](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edd)

### H-index

We initialize the H-index with 0, and after adding each paper, we need to update the current H-index.

- the order of numbers in the vector are non-decreasing.

- use lower bound method to find the location where current citation number inserts in the vector.

- use lower bound method to find the current H-index answer.

---

### Elevangram

We need to divide each digits to two partitions: positive partition and negative partition, 

where positive partition means the digit is on the odd index (be calculated as add), 

and negative partition means the digit is in the even index (be calculated as minus).

**Reduce the number(Ai) of each digit(1-9):**

By placing some i's on the (+)left side and others on the (-)right side.

For **example i = 2, and a[i] = 3.** Sums list will be as follows:

```
      | 2 2 2 -> -2 -2 -2 = -6
      
2     | 2 2   -> +2 -2 -2 = -2

2 2   | 2     -> +2 +2 -2 = +2

2 2 2 |       -> +2 +2 +2 = +6
```

Let's take an example where i = 1, and Ai = 20.

Sums will be: [0, 2, 4, 8, 10, 12, 14, 16, 18, 20]

Sums%11: [0, 2, 4, 8, 10, 1, 3, 5, 7, 9], which basically covers all numbers in range [0, 10].

Reference : 

**Dynamic programming method:**

- Let dp(i, j, k) denote if it is possible to achieve the state
  
  ```
  i: current digit
  
  j: number of digits in the current positive partition
  
  k: current sum(|positive partition-negative partition|) modulo 11
  ```
  
- Two case (select or not select):

  ```
  1. Select the current digit -> positive partition
  
  dp(i, j+1, (k + current_digit) % 11) |= dp(i-1, j, k)
  
  2. Not select the current digit -> negative partition
  
  dp(i, j, (k - current_digit + 11) % 11) |= dp(i-1, j, k)
  
  ```  
