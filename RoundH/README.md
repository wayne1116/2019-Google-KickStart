## [Round G](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edd)

### H-index

We initialize the H-index with 0, and after adding each paper, we need to update the current H-index.

- the order of numbers in the vector are non-decreasing.

- use lower bound method to find the location where current citation number inserts in the vector.

- use lower bound method to find the current H-index answer.

---

### Elevangram

**Reduce the number(Ai) of each digit(1-9):**

given a[i] is greater than or equal to 20

**Dynamic programming method:**

We need to divide each digits to two partitions: positive partition and negative partition, 

where positive partition means the digit is on the odd index (be calculated as add), 

and negative partition means the digit is in the even index (be calculated as minus).


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
